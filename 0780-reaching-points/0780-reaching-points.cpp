class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if (sx == 0 && sy == 0)
            return 0;
        if (sx == tx || sy == ty) {
            if (sx == tx && sy == ty || sx == tx && ty == sy + sx ||
                sy == ty && tx == sy + sx)
                return 1;
            else
                0;
        }

        while (sx < tx && sy < ty) {
            if (tx > ty) {
                tx %= ty;
            } else {
                ty %= tx;
            }
        }

        if (tx == sx) {
            return ty >= sy && (ty - sy) % tx == 0;
        }

        if (ty == sy) {
            return tx >= sx && (tx - sx) % ty == 0;
        }

        return 0;
    }
};