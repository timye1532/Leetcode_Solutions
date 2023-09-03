class LFUCache {
public:
    int capacity;
    int minFreq;
    // key -> pair(value, frequency)
    unordered_map<int, pair<int, int>> keyVal;
    // frequency -> linked_list(keys)
    unordered_map<int, list<int>> freqList;
    // key -> linked_list::iterator, store the position of the key in LinkedList
    unordered_map<int, list<int>::iterator> pos;

    LFUCache(int capacity) {
        // initialize the capacity and minFreq
        this->capacity = capacity;
        this->minFreq = 0;
    }
    
    int get(int key) {
        // if cannot find the key, return -1
        if (keyVal.find(key) == keyVal.end())
            return -1;
        // get the freq for given key, then freq++ and update the freqList
        // erase the original freq of key in freqList, add freq+1 of key in freqList
        int freq = keyVal[key].second;
        freqList[freq].erase(pos[key]);
        freq++;
        keyVal[key].second = freq;
        freqList[freq].push_back(key);
        pos[key] = --freqList[freq].end();

        // after updating the freqList, if we find the minFreq in freqList is empty, minFreq++
        if (freqList[minFreq].empty())
            minFreq++;
        return keyVal[key].first;
    }
    
    void put(int key, int value) {
        if(!capacity)
            return;
        // if the given key is already exist, alter the keyVal, update freqList
        if(keyVal.find(key) != keyVal.end()) {
            keyVal[key].first = value;
            int freq = keyVal[key].second;
            freqList[freq].erase(pos[key]);
            freq++;
            keyVal[key].second = freq;
            freqList[freq].push_back(key);
            pos[key] = --freqList[freq].end();
            
            // for same reason, if minFreq in freqList is empty, minFreq++
            if(freqList[minFreq].empty())
                minFreq++;
            return;
        }
        
        // check if the capacity is reached, then we need to delete the least frequency item
        if(keyVal.size() == capacity) {
            int delKey = freqList[minFreq].front();
            keyVal.erase(delKey);
            pos.erase(delKey);
            freqList[minFreq].pop_front();
        }

        // for now the key is a new one, then freq = 1, minFreq = 1
        keyVal[key] = {value,1};
        freqList[1].push_back(key);
        pos[key] = --freqList[1].end();
        minFreq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */