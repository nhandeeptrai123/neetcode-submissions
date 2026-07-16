class MyQueue {
private: 
    stack <int> st1;
    stack <int> st2;

    void transfer() {
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
    }
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        transfer(); //đảm bảo st2 có phần tử đứng đầu 
        int val = st2.top();
        st2.pop();
        return val;
    }
    
    int peek() {
        transfer();
        return st2.top();
    }
    
    bool empty() {
        return st2.empty() && st1.empty();
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