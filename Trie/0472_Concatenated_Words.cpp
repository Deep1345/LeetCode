// Problem   : 472. Concatenated Words
// Difficulty: Hard
// Tags      : Array, String, Dynamic Programming, Depth-First Search, Trie, Sorting
// URL       : https://leetcode.com/problems/concatenated-words/
// Language  : Cpp
// Date      : 2026-08-19
//

class Solution {
public:

    bool solve(string& word, int start, unordered_set<string>& st,
               vector<int>& dp) {
        if(start == word.size())
            return true;
        if(dp[start] != -1)
            return dp[start];
        string prefix = "";
        for(int i = start; i < word.size(); i++) {
            prefix += word[i];
            // prefix exists in dictionary
            if(st.find(prefix) != st.end()) {
                if(solve(word, i + 1, st, dp))
                    return dp[start] = true;
            }
        }
        return dp[start] = false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> st(words.begin(), words.end());
        vector<string> ans;
        for(string word : words) {
            st.erase(word);
            int n = word.size();
            vector<int> dp(n, -1);
            if(solve(word, 0, st, dp))
                ans.push_back(word);
            st.insert(word);
        }
        return ans;
    }
};