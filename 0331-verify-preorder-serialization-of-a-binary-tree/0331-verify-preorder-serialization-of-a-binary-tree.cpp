class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> tokens;
        string curr = "";

        for (char c : preorder) {
            if (c == ',') {
                tokens.push_back(curr);
                curr = "";
            } else {
                curr += c;
            }
        }
        tokens.push_back(curr);

        stack<string> st;
        for (string node : tokens) {
            while (node == "#" && !st.empty() && st.top() == "#") {
                st.pop();
                if (st.empty())
                    return false;
                st.pop();
            }
            st.push(node);
        }

        return st.size() == 1 && st.top() == "#";
    }
};