class Solution {
public:
    int reverseBits(int n) {
        uint32_t bits = 0;
        int index = 0;

        while (n) {
            if ((n & 1) == 1)
                bits |= (1U << (31-index));
            index++;
            n >>= 1;
        }

        return bits;
    }
};