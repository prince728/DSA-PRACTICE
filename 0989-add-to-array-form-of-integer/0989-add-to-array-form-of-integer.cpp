class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        if (k == 0)
            return num;

        vector<int> ans;
        int carry = 0,index=num.size()-1;

        while (k || index >= 0 || carry) {
            int sum = carry;
            if(index>=0){
                sum+=num[index];
                index--;
            } 
            if (k) {
                int lastDigit = k % 10;
                sum += lastDigit;
                k /= 10;
            }

            carry = sum / 10;
            int digit = sum % 10;

            ans.push_back(digit);
        }
        
        reverse(ans.begin(),ans.end());

        return ans;
    }
};