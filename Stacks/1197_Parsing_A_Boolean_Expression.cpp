// Problem   : 1197. Parsing A Boolean Expression
// Difficulty: Hard
// Tags      : String, Stack, Recursion
// URL       : https://leetcode.com/problems/parsing-a-boolean-expression/
// Language  : Cpp
// Date      : 2026-08-17
//

class Solution {
public:
    
    char solve(char expr,vector<char>& temp){
        if(expr=='&'){
            for(int i=0;i<temp.size();i++){
                if(temp[i]=='f'){
                    return 'f';
                }
            }
            return 't';
        }
        else if(expr == '|'){
            for(int i=0;i<temp.size();i++){
                if(temp[i]=='t'){
                    return 't';
                }
            }
            return 'f';
        }
        else{
            if(temp[0]=='t'){
                return 'f';
            }
            else{
                return 't';
            }
        }
    }
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for(auto c: expression){
            if(c==','){
                continue;
            }
            else if(c!=')'){
                st.push(c);
            }
            else{
                vector<char> temp;
                while(st.top()!='('){
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char expr = st.top();
                st.pop();
                st.push(solve(expr,temp));
            }
        }
        if(st.top()=='t'){
            return true;
        }
        else{
            return false;
        }
    }
};