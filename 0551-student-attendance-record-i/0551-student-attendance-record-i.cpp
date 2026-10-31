class Solution {
public:
    bool checkRecord(string s) {
        int A = 0, LConsecutive = 0, index = 0, count = 0;
        while (index < s.size()) {

            while (s[index] == 'L') {
                index++;
                count++;
            }
            if (s[index] == 'A') {
                A++;
            }
            LConsecutive = max(LConsecutive, count);
            count = 0;
            index++;
        }

        return A < 2 && LConsecutive < 3;
    }
};