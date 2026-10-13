class Solution {
public:
    pair<int, int> findDivisor(int num) {
        int sum = 0;
        int count = 0;

        if (num < 1)
            return {0, 0};

        for (int i = 1; i * i <= num; i++) {
            if (num % i == 0) {
                count++;
                sum += i;
                if (i != num / i) {
                    count++;
                    sum += (num / i);
                }
            }
            if (count > 4)
                break;
        }

        return pair<int, int>{count, sum};
    }

    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            int count = findDivisor(nums[i]).first;
            int sum = findDivisor(nums[i]).second;
            if (count == 4)
                ans += sum;
        }

        return ans;
    }
};