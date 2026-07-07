class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0, sum = 0,p=0;

        while (n) {
            if (n % 10 != 0) {
                int curr = n % 10;
                x += curr *pow(10,p);
                p++;
                sum += curr;
            }
            n/=10;
        }
        return sum*x;
    }
};