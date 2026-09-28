class Solution {
public:
    long long zeroes(int a) {
        long long count = 0;
        while (a >= 5) {
            a /= 5;
            count += a;
        }
        return count;
    }
    long long binarySearch(int k) {
        if (k < 0) return -1;
        long long first = 0, last = 5LL * k + 4;

        while (first < last) {
            long long mid = first + (last - first + 1) / 2;
            if (zeroes(mid) <= k)
                first = mid;
            else
                last = mid - 1;
        }
        return first;
    }
    int preimageSizeFZF(int k) {
        long long x = binarySearch(k);
        long long y = binarySearch(k - 1);

        return x - y;
    }
};