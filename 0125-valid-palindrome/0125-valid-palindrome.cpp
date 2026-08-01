class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for (char& c : s) {
            if (c >= '0' && c <= '9') {
                str += c;
            } 
            else if (c <= 90 && c >= 65) {
                str += static_cast<char>(tolower(c));
            }else if (c <= 122 && c >= 97) {
                str += c;
            }
        }
        int first = 0,last=str.size()-1;

        while(first<last){
            if(str[first]!=str[last])return 0;
            first++;
            last--;
        }
        return 1;
    }
};