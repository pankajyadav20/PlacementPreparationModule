class MyCalendarThree {
public:
    map<int , int> mp;
    int maxi , cur;
    MyCalendarThree() {
            maxi  = 0;
            cur = 0;
    }
    
    int book(int start, int end) {
        
        mp[start] += 1;
        mp[end] -= 1;
        for(auto it : mp){
            cur += it.second;
            maxi = max(maxi ,cur);
        }
        return maxi;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */