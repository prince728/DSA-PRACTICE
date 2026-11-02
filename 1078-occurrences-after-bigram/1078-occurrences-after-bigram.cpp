class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        stringstream ss(text);
        string token;
        vector<string> tokens, ans;

        while (getline(ss, token, ' ')) {
            tokens.push_back(token);
        }

        int index = 0;

        while (index < tokens.size() - 2) {
            if (tokens[index] == first) {
                if (tokens[index + 1] == second)
                    ans.push_back(tokens[index + 2]);
            }
            index++;
        }

        return ans;
    }
};