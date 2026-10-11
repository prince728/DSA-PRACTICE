class Solution {
public:
    string freqAlphabets(string s) {
        int n= s.size();
        string ans="";
        for(int i=n-1;i>=0;i--){
            int num;
            if(s[i]=='#'){
                num=stoi(s.substr(i-2,2));
                i-=2;
            }else num=s[i]-'0';

           ans += (char)((num - 1) + 'a');

        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};