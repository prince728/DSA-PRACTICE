class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        // Store 1-based index of last seen character position
        int last_seen_s[256] = {0};
        int last_seen_t[256] = {0};

        for (int i = 0; i < s.size(); i++) {
            // If their last tracking positions don't match, they aren't isomorphic
            if (last_seen_s[s[i]] != last_seen_t[t[i]]) {
                return false;
            }
            // Update to current index + 1 (to avoid default 0 conflict)
            last_seen_s[s[i]] = i + 1;
            last_seen_t[t[i]] = i + 1;
        }

        return true;
    }
};
