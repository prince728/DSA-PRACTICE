class Solution {
public:
    bool compare(string word2, vector<char> odd1, vector<char> even1) {
        vector<char> odd2, even2;
        for (int i = 0; i < word2.size(); i++) {
            if (i % 2 == 0) {
                odd2.push_back(word2[i]);
            } else {
                even2.push_back(word2[i]);
            }
        }
        sort(odd2.begin(), odd2.end());
        sort(even2.begin(), even2.end());

        return odd1 == odd2 && even1 == even2;
    }

    int numSpecialEquivGroups(vector<string>& words) {
        int n = words.size(), ans = 0;
        vector<bool> visited(words.size(), 0);

        for (int i = 0; i < n; i++) {
            if (visited[i] != 1) {

                vector<char> odd1, even1;
                for (int k=0;k<words[i].size();k++) {
                    if (k % 2 == 0) {
                        odd1.push_back(words[i][k]);
                    } else {
                        even1.push_back(words[i][k]);
                    }
                }
                sort(odd1.begin(), odd1.end());
                sort(even1.begin(), even1.end());

                int group = 1;
                for (int j = i + 1; j < n; j++) {
                    if (visited[j] != 1 && compare(words[j], odd1, even1)) {
                        group++;
                        visited[j] = 1;
                    }
                }
                ans++;
            }
        }

        return ans;
    }
};