class Solution {
public:
    string alphabetBoardPath(string target) {
        string ans = "";
        int currR = 0, currC = 0;

        pair<int, int> curr = {0, 0};

        for (char c:target) {
            int nextR = (c - 'a') / 5;
            int nextC = (c - 'a') % 5;

            while (currR > nextR) {
                ans += 'U';
                currR--;
            }
            while (currC > nextC) {
                ans += 'L';
                currC--;
            }
            while (currR < nextR) {
                ans += 'D';
                currR++;
            }
            while (currC < nextC) {
                ans += 'R';
                currC++;
            }
            ans += '!';
        }

        return ans;
    }
};