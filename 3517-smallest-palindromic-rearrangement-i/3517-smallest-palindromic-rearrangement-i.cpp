class Solution {
public:
    string smallestPalindrome(string s) {
        if (s.size() < 2)
            return s;

        char extra;
        if (s.size() % 2 == 1)
            extra = s[s.size() / 2];

        string sub1 = s.substr(0, s.size() / 2);
        sort(sub1.begin(), sub1.end());

        string sub2 = sub1;
        reverse(sub2.begin(), sub2.end());

        return s.size()%2==1?sub1+extra+sub2:sub1+sub2;
    }
};