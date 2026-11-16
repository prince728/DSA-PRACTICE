class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            string curr = "";
            for (int i = 0; i < s.size(); i+=k) {
                int sum = 0;
                for (int j = i; j < i + k && j < s.size(); j++) {
                    sum += s[j] - '0';
                }
                curr += to_string(sum);
            }
            s = curr;
        }

        return s;
    }
};