class Solution {
public:
    int nums[10] = {0};
    int size;
    long long factorial(int n) {
        if (n == 0 || n == 1)
            return 1;
        return factorial(n - 1) * n;
    }

    int findNthAvailable(int step) {
        int count = 0;
        for (int i = 1; i <= size; i++) {
            if (!nums[i]) {
                if (count == step)
                    return i;
                count++;
            }
        }
        return -1;
    }

    char constructNumber(int n, int& k) {
        int fact = factorial(n - 1);

        int indexToPick = (k - 1) / fact;

        k -= indexToPick * fact;

        int num = findNthAvailable(indexToPick);

        nums[num] = 1;

        return '0' + num;
    }

    string getPermutation(int n, int k) {
        size = n;
        string ans = "";
        for (int i = n; i > 0; i--) {
            ans += constructNumber(i, k);
        }

        return ans;
    }
};