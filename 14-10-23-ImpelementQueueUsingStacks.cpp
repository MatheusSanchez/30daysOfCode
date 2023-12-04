/*
    Time: O(n) - O(1) amortized / n == input.size
    Space: O(n)
*/

class MyQueue {

    stack<int> inStack;
    stack<int> outStack;

public:
    MyQueue() {
        
    }
    
    void push(int x) { // O(1)
        inStack.push(x);
    }
    
    int pop() { //O(n)
        peek();
        int outStackTop = outStack.top();
        outStack.pop();

        return outStackTop;
    }
    
    int peek() { // O(n)
        if(outStack.empty()){
            while(!inStack.empty()){
                outStack.push(inStack.top());
                inStack.pop();
            }
        }

        return outStack.top(); 
    }
    
    bool empty() { //O(1) 
        return outStack.empty() && inStack.empty();
    }

};