class Solution {
public:
    string reverseParentheses(string s) {
        string ans = "";

        stack<char> st;

        int start = 1;
        for (int start = 0; start < s.size(); start++) {

            if (s[start] == ')') {
                string temp="";
                while (!st.empty() && st.top() != '(') {
                    temp += st.top();
                    st.pop();
                }
                if (!st.empty())
                    st.pop();

                for (int i = 0; i < temp.size(); i++) {
                    st.push(temp[i]);
                }
            } else
                st.push(s[start]);
        }


        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }

        return ans;
    }
};