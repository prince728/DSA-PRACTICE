class Solution {
public:
    string largestOddNumber(string num) {
        while(num.size()!=0){
            if((num[num.size()-1]-'0')%2==1) break;
            else{
                num.pop_back();
            }
        }

        return num;
    }
};