class MyCalendarTwo {
public:
    vector<pair<int, int>> book_once;
    vector<pair<int, int>> book_twice;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        vector<pair<int, int>>::iterator iter1;
        vector<pair<int, int>>::iterator iter2;;
        for (iter2 = book_twice.begin(); iter2 != book_twice.end(); ++iter2) {
            if (iter2->first < end && iter2->second > start) return false;
        }
        
        for (iter1 = book_once.begin(); iter1 != book_once.end(); ++iter1) {
            if (iter1->first < end && iter1->second > start) {
                book_twice.push_back({max(start, iter1->first), min(end, iter1->second)});
            }
        }
        book_once.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */