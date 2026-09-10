// Problem   : 225. Implement Stack using Queues
// Difficulty: Easy
// Tags      : Stack, Design, Queue
// URL       : https://leetcode.com/problems/implement-stack-using-queues/
// Language  : Cpp
// Date      : 2026-09-10
//

class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int n = q.size();
        for(int i=1;i<n;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int ans = q.front();
        q.pop();
        return ans;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */