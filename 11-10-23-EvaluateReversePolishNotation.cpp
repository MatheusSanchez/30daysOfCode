/*
    Time: O(n) n == number.size()
    Space: O(n) 
    https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
*/

class Solution {
    bool isNumber(string number){
        
        char* p;
        strtol(number.c_str(), &p, 10);

        if (*p) {
            return false;
        }
        
        return true;
    }

public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for(int i = 0; i < tokens.size(); i++){
            if(isNumber(tokens[i])){
                s.push(stoi(tokens[i]));
            }else{
                if(tokens[i] == "+"){
                    sumOperation(s);
                }else if(tokens[i] == "-"){
                    minorOperation(s);
                }else if(tokens[i] == "/"){
                    divideOperation(s);
                }else if(tokens[i] == "*"){
                    timesOperation(s);
                }
            }
        }


        return s.top();
    }

    void sumOperation(stack<int> &s){
        int firstTop = s.top();
        s.pop();
        int secondTop = s.top();
        s.pop();

        s.push(firstTop+secondTop);
    }

    void minorOperation(stack<int> &s){
        int firstTop = s.top();
        s.pop();
        int secondTop = s.top();
        s.pop();

        s.push(secondTop-firstTop);
    }

    void timesOperation(stack<int> &s){
        int firstTop = s.top();
        s.pop();
        int secondTop = s.top();
        s.pop();

        s.push(firstTop*secondTop);
    }

    void divideOperation(stack<int> &s){
        int firstTop = s.top();
        s.pop();
        int secondTop = s.top();
        s.pop();

        s.push(secondTop/firstTop);
    }
};


