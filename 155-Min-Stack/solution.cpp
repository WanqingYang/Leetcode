class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
         
    }
    
    void push(int x) {
        st.push(x);
        //int minTop = minSt.top();
        if(!minSt.empty() && minSt.top() < x) {
            minSt.push(minSt.top());
        } else{
            minSt.push(x);
        }
    }
    
    void pop() {
        st.pop();
        minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
private:
    stack<int> st;
    stack<int> minSt;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */