class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str2.size() == 0 || str1.size() == 0)
            return "";
        if (str1.size() > str2.size())
            return gcd(str1, str2);
        return gcd(str2, str1);
    }
    string gcd(string str1, string str2) {
        string prefixSum = "", ans = "";
        for (int i = 0; i < str2.size(); i++) {
            prefixSum += str2[i];
            int mul = str1.size() / prefixSum.size();
            string curr = "";
            bool flag = 0;
            for (int i = 0; i < mul; i++) {
                curr += prefixSum;
                if (curr == str2)
                    flag = 1;
            }
            if (curr == str1 && flag == 1)
                ans = prefixSum;
        }

        return ans;
    }
};