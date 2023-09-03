class MyCalendarThree {
public:
    map<int, int> point_count;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        point_count[start]++;
        point_count[end]--;
        
        int res = 0; int cur = 0;
        map<int, int>::iterator iter;
        for (iter = point_count.begin(); iter != point_count.end(); ++iter) {
            cur += iter->second;
            res = max(res, cur);
        }
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */