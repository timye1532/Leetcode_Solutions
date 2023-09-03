class MyCalendar {
public:
    vector<pair<int, int>> overlap;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        vector<pair<int, int>>::iterator iter;
        for (iter = overlap.begin(); iter != overlap.end(); ++iter) {
            if (iter->first < end && iter->second > start) return false;
        }
        overlap.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */