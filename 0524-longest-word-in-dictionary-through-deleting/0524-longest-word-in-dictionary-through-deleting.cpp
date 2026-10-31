class Solution {
public:
    bool wordInDict(string s , string word) {
        int i=0,j=0;
        while(i<s.size()){
            if(s[i]==word[j]){
                j++;
            }
            i++;
        }
        return j==word.size();
    }

    string lexicographicalOrder(string a, string b){
        for(int i=0;i<a.size();i++){
            if(a[i]<b[i])return a;
            else if(a[i]>b[i])return b;
        }
        return "";
    }


    string findLongestWord(string s, vector<string>& dictionary) {

        string maxString = "";
        for(int i=0;i<dictionary.size();i++){
            if(s==dictionary[i]) return s;
            if(wordInDict(s,dictionary[i])){
                if(dictionary[i].size()>maxString.size())
                maxString= dictionary[i];
                else if(dictionary[i].size()==maxString.size()){
                    maxString =lexicographicalOrder(maxString,dictionary[i]);
                }
            }
        }

        return maxString;
    }
};