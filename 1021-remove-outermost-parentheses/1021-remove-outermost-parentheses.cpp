class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int>st;
        string ans="";

        for(int i=0;i<s.size();i++){
            if(s[i]=='(') st.push(i);
            else if(s[i]==')'){
                if(st.size()==1) ans+= s.substr(st.top()+1,i-st.top()-1);
                st.pop();
            }
        }

        return ans;
    }
};