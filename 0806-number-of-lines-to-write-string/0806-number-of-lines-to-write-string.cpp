class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int line = 1;
        int width = 0;

        for (int i = 0; i < s.size(); i++) {
            if (width + widths[s[i] - 'a'] <= 100)
                width += widths[s[i] - 'a'];
            else {
                line++;
                width = widths[s[i] - 'a'];
            }
        }

        return vector<int>{line, width};
    }
};