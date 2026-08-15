class Solution {
public:
    string reverseWords(string s) {
        int i=0;
        while(i < s.length()){
            int left = i;
            int end = i;

            while(end < s.length() && s[end] != ' '){
                end++;
            }
            int right = end-1;
            i=end+1;

            while(left < right){
                swap(s[left], s[right]);
                left++; right--;
            }
        }
        return s;
    }
};