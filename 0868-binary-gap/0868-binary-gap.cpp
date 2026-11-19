class Solution {
public:
    int binaryGap(int n) {
        bool counting = false;
        int gap = 0, ans = 0;
        while (n) {
            if (n & 1) {
                if (counting)
                    ans = max(ans, gap);
                counting = true;
                gap = 1;
            }else if (counting) {
                gap++;   
            }
            n >>= 1;
        }

        return ans;
    }
};