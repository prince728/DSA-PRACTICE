class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> ans;
        bool in_block = 0;
        string s = "";

        for (int i = 0; i < source.size(); i++) {
            string line = source[i];
            for (int j = 0; j < line.size(); j++) {
                if (!in_block) {
                    if (j + 1 < line.size() && line[j] == '/' &&
                        line[j + 1] == '/') {
                        break;
                    } else if (j + 1 < line.size() && line[j] == '/' &&
                               line[j + 1] == '*') {
                        in_block = true;
                        j++;
                    } else {
                        s += line[j];
                    }
                } else {
                    if (j + 1 < line.size() && line[j] == '*' &&
                        line[j + 1] == '/') {
                        in_block = false;
                        j++;
                    }
                }
            }
            if (!in_block && !s.empty()) {
                ans.push_back(s);
                s = "";
            }
        }

        return ans;
    }
};