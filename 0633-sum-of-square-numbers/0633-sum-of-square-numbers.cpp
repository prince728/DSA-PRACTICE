class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left = 0, right=sqrt(c);

        while (left <= right) {
            long long sum = left * left + right * right;
            if (sum == c)
                return 1;
            if (sum < c) {
                left++;
            } else {
                right--;
            }
        }

        return 0;
    }
};