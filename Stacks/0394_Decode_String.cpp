// Problem   : 394. Decode String
// Difficulty: Medium
// Tags      : String, Stack, Recursion
// URL       : https://leetcode.com/problems/decode-string/
// Language  : Cpp
// Date      : 2026-09-11
//

class Solution {
public:
    string decodeString(string s) {

        stack<int> count;
        stack<string> str;

        string current = "";
        int num = 0;

        for(int i = 0; i < s.size(); i++){

            if(isdigit(s[i])){
                num = num * 10 + (s[i] - '0');
            }

            else if(s[i] == '['){

                count.push(num);
                str.push(current);

                num = 0;
                current = "";
            }

            else if(s[i] == ']'){

                int times = count.top();
                count.pop();

                string previous = str.top();
                str.pop();

                string temp = "";

                for(int j = 0; j < times; j++){
                    temp += current;
                }

                current = previous + temp;
            }

            else{
                current += s[i];
            }
        }

        return current;
    }
};