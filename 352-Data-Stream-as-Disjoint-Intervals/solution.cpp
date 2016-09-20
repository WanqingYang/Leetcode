/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
/*class SummaryRanges {
public:
    /** Initialize your data structure here. **/
    /*SummaryRanges() {
        
    }
    
    void addNum(int val) {
        
    }
    
    vector<Interval> getIntervals() {
        
    }
};*/

/*class SummaryRanges {
public:
    void addNum(int val) {
        auto Cmp = [](Interval a, Interval b) { return a.start < b.start; };
        auto it = lower_bound(vec.begin(), vec.end(), Interval(val, val), Cmp);
        int start = val, end = val;
        if(it != vec.begin() && (it-1)->end+1 >= val) it--;
        while(it != vec.end() && val+1 >= it->start && val-1 <= it->end)
        {
            start = min(start, it->start);
            end = max(end, it->end);
            it = vec.erase(it);
        }
        vec.insert(it,Interval(start, end));
    }
    
    vector<Interval> getIntervals() {
        return vec;
    }
private:
    vector<Interval> vec;
};*/

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    void addNum(int val) {
        auto it = st.lower_bound(Interval(val, val)); //know where the val's index is, in the st
        int start = val, end = val;
        if(it != st.begin() && (--it)->end+1 < val) {it++;} //it is neither the first nor???????
        while(it != st.end() && val+1 >= it->start && val-1 <= it->end)// not the last, and val is in the
        {
            start = min(start, it->start);
            end = max(end, it->end);
            it = st.erase(it);
        }
        st.insert(it,Interval(start, end));
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> result;
        for(auto val: st) result.push_back(val);
        return result;
    }
private:
    struct Cmp{
        bool operator()(Interval a, Interval b){ return a.start < b.start; }
    };
    set<Interval, Cmp> st;//pass interval and functor, tell us the sorting method
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */