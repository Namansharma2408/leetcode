class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        int n = s2.size();
        for( int i = 0 ; i < n ; i++){
            s1.push(s2.top());
            s2.pop();
        } 
        s2.push(x);
        for( int i = 0 ; i < n ; i++){
            s2.push(s1.top());
            s1.pop();
        } 
    }
    
    int pop() {
        int x = s2.top();
        s2.pop();
        return x;
    }
    
    int peek() {
        return s2.top();
    }
    
    bool empty() {
        if( s2.empty()) return true;
        else return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
