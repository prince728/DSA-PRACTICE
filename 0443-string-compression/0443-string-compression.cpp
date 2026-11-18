class Solution {
public:
    int compress(vector<char>& chars) {
        int count = 0;
        string s = "";
        for (int i = 0; i < chars.size() - 1; i++) {
            count++;
            if (chars[i] != chars[i + 1]) {
                s += chars[i];
                if (count != 1)
                    s += to_string(count);

                count = 0;
            }
        }
        s += chars[chars.size() - 1];
        if (++count != 1)
            s += to_string(count);

        chars.clear();

        for (char c : s) {
            chars.push_back(c);
        }

        return s.size();
    }
};