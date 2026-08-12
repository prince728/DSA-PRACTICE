class Solution {
public:
    int sumDivisible(int n, int k) {
        int m = n / k;
        return k * m * (m + 1) / 2;
    }
    int sumOfMultiples(int n) {
        return sumDivisible(n, 3) + sumDivisible(n, 5) + sumDivisible(n, 7) -
               sumDivisible(n, 15) - sumDivisible(n, 21) - sumDivisible(n, 35) +
               sumDivisible(n, 105);
    }
};