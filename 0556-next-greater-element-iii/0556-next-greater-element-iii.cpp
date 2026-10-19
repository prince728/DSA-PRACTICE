class Solution {
public:
    int nextGreaterElement(int nums) {
        string num = to_string(nums);

        int n = num.size(), first = n - 1, i;

        for (i = n - 2; i >= 0; i--) {
            if (num[i] < num[i + 1]) {
                while (num[first] <= num[i])
                    first--;
                swap(num[i], num[first]);
                break;
            }
        }
        if (i == -1)
            return -1;

        reverse(num.begin()+i+1,num.end());

        long long ans = stoll(num);

        return ans<=INT_MAX?(int)ans:-1;
    }
};