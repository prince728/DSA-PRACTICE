class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string, int> uniqueEmail;
        for (int i = 0; i < emails.size(); i++) {
            string email = "";
            int index = 0;
            bool ignore = 0;
            while (emails[i][index] != '@') {

                if (emails[i][index] == '+') {
                    ignore = true;
                }
                if (!ignore && emails[i][index] != '.')
                    email += emails[i][index];

                index++;
            }
            email += emails[i].substr(index);

            uniqueEmail[email]++;
        }

        return uniqueEmail.size();
    }
};