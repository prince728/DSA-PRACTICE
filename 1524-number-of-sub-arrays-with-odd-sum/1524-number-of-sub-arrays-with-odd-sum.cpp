class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int even = 1, odd = 0, sum = 0, ans = 0,MOD=1e9 + 7;

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i]%2;
            if (sum % 2 == 0) {
                ans += odd;
                even++;
            } else {
                ans += even;
                odd++;
            }
            ans%=MOD;
        }
        return ans;
    }
};