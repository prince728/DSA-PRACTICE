#include <vector>
#include <queue>
#include <numeric>

class Solution {
public:
    bool isPossible(vector<int>& target) {
        if (target.size() == 1) {
            return target[0] == 1;
        }

        priority_queue<int> pq;
        long long total_sum = 0;

        for (int num : target) {
            pq.push(num);
            total_sum += num;
        }

        while (pq.top() > 1) {
            int max_val = pq.top();
            pq.pop();

            long long rest_sum = total_sum - max_val;
            if (rest_sum == 1) {
                return true;
            }

            if (max_val <= rest_sum || rest_sum == 0 || max_val % rest_sum == 0) {
                return false;
            }

            int updated_val = max_val % rest_sum;
            total_sum = rest_sum + updated_val;
            pq.push(updated_val);
        }

        return true;
    }
};
