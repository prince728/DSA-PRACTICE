class Solution {
public:
    vector<string> findWords(vector<string>& words) {

        vector<string> ans;
        unordered_map<char, int> mp;

        string firstRow = "qwertyuiop";
        string secondRow = "asdfghjkl";
        string thirdRow = "zxcvbnm";

        for (int i = 0; i < firstRow.size(); i++){
            mp[firstRow[i]] = 1;
            mp[toupper(firstRow[i])] = 1;
        }

        for (int i = 0; i < secondRow.size(); i++){
            mp[secondRow[i]] = 2;
            mp[toupper(secondRow[i])] = 2;
        }

        for (int i = 0; i < thirdRow.size(); i++){
            mp[thirdRow[i]] = 3;
            mp[toupper(thirdRow[i])] = 3;
        }

        for (string word : words) {
            int row = mp[word[0]];
            int j = 1;
            while (mp[word[j]] == row)
                j++;
            if (j == word.size())
                ans.push_back(word);
        }

        return ans;
    }
};