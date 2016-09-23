/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 //first time write by myself
class SummaryRanges {
public:
    /** Initialize your data structure here. **/
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        auto it = st.lower_bound(Interval(val, val));
        int start = val, end = val;
        //check which interval the val should be in
        if(it != st.begin() && (--it)->end + 1 < val) {it++;}
        while(it != st.end() && val >= it->start - 1 && val <= it->end + 1) {
            start = min(start, it->start);
            end = max(end, it->end);
            it = st.erase(it);
        }
        st.insert(it, Interval(start, end));
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> result;
        for(val: st) {result.push_back(val);}
        return result;
    }
private:
    struct cmp {
        bool operator()(Interval a, Interval b) {return a.start < b.start;}
    };
    set<Interval, cmp> st;

};

/*class SummaryRanges {
public:
    /** Initialize your data structure here. */
   /* void addNum(int val) {
        auto it = st.lower_bound(Interval(val, val)); //know where the val's index is, in the st
        int start = val, end = val;
        if(it != st.begin() && (--it)->end+1 < val) {it++;} //it is neither the first nor the next
        while(it != st.end() && val+1 >= it->start && val-1 <= it->end)
        //not the last, and val is in the
        {
            start = min(start, it->start);
             end = max(end, it->end);
            it = st.erase(it); //return an iterator to the element that follows the last element //removed (or set::end, if the last element was removed).

        }
        st.insert(it,Interval(start, end));//insert the interval into position before it; 
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