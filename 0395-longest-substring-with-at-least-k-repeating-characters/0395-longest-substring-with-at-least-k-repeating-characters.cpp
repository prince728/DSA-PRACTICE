class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.size() == 0 || k > s.size()) return 0;
        if (k <= 1) return s.size();

        int start = 0, end = 0;
        unordered_map<char, int> mp;

        for (char ch : s) {
            mp[ch]++;
        }

        while (end < s.size()) {
            if (mp[s[end]] < k) {
                int leftValidWindow = longestSubstring(s.substr(start, end - start), k);
                
                while (end < s.size() && mp[s[end]] < k) {
                    end++;
                }
                
                int rightValidWindow = longestSubstring(s.substr(end), k);
                
                return max(leftValidWindow, rightValidWindow);
            }
            end++;
        }

        // If the loop finished without hitting an invalid character, the entire current window is valid
        return s.size();
    }
};
