class Solution {
public:
    bool checkVowel(char c) {
        return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'a'|| c == 'e' || c == 'i' || c == 'o' || c == 'u';

    }
    string toGoatLatin(string sentence) {
        stringstream ss(sentence);
        string word;
        vector<string> words;
        string ans="";

        while (ss >> word) {
            words.push_back(word);
        }
        int index=1;
        for (auto& word : words) {
            if (!checkVowel(word[0])){
                word=word+word[0];
                word= word.substr(1);
            }
            word+="ma";
            for(int i=0;i<index;i++) word+='a';

            index++;

            ans+=word+" ";
            
        }

        return ans.substr(0,ans.size()-1);
    }
};