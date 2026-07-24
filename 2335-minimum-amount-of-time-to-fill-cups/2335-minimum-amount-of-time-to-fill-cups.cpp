class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;
        int count = 0;
        for (int i = 0; i < amount.size(); i++) {
            if (amount[i])
                pq.push(amount[i]);
        }

        while (pq.size() > 1) {
            int first = pq.top();
            pq.pop();
            int second = 0;

            second = pq.top();
            pq.pop();

            if (--first)
                pq.push(first);

            if (--second)
                pq.push(second);

            count++;
        }

        while (!pq.empty()) {
            int first = pq.top();
            pq.pop();
            if (--first)
                pq.push(first);
            
            count++;
        }

        return count;
    }
};