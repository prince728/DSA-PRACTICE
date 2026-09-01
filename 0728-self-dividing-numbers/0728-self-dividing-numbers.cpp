class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;

        for (int i = left; i <= right; i++) {
            string s = to_string(i);
            bool check = 1;
            for (int j = 0; j < s.size(); j++) {
                if (s[j] == '0' || i % (s[j] - '0') != 0) {
                    check = 0;
                    break;
                }
            }
            if (check)
                ans.push_back(i);
        }

        return ans;
    }
};