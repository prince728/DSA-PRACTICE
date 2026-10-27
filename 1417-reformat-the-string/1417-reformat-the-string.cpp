class Solution {
public:
    string reformat(string s) {
        string ans = "";
        int cntDigit = 0, cntLetter = 0, n = s.size();
        string letters="";
        string digits="";

        for (int i = 0; i < n; i++)
            if (isdigit(s[i])){
                cntDigit++;
                digits.push_back(s[i]);
            }
            else{
                cntLetter++;
                letters.push_back(s[i]);
            }

        int diff = cntDigit-cntLetter;
        if(diff>1 || diff<-1) return "";

        if(diff==1){
            int index=0;
            while(index<digits.size()){
                ans+=digits[index];
                if(letters[index]) ans+=letters[index];
                index++;
            }
        }
        else{
            int index=0;
            while(index<letters.size()){
                ans+=letters[index];
                if(digits[index]) ans+=digits[index];
                index++;
            } 
        }

        return ans;

        
    }
};