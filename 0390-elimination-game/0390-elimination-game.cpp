class Solution {
public:
    int lastRemaining(int n) {
        int head = 1;
        int step = 1;
        int remaining = n;
        bool left_to_right = true;

        while (remaining > 1) {
            if (left_to_right || remaining % 2 == 1) {
                head += step;
            }

            
            remaining /= 2;
            step *= 2;
            left_to_right = !left_to_right; 
        }

        return head;
    }
};
