class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> ans(n, 0);
        
        int c_pos = -100000; 
        
        for (int i = 0; i < n; i++) {
            if (s[i] == c) {
                c_pos = i;
            }
            ans[i] = i - c_pos;
        }
        
        c_pos = 100000;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == c) {
                c_pos = i;
            }
            ans[i] = min(ans[i], c_pos - i);
        }
        
        return ans;
    }
};
