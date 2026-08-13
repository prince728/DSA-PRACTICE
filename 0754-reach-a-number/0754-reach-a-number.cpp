class Solution {
public:
    int reachNumber(int target) {
        target = abs(target); 
        
        long long first = 0;
        long long last = 2 * (long long)target;
        long long ans = last;
        
        while (first <= last) {
            long long mid = first + (last - first) / 2;
            long long current_sum = mid * (mid + 1) / 2;
            
            if (current_sum >= target) {
                ans = mid;      
                last = mid - 1; 
            } else {
                first = mid + 1; 
            }
        }
    
        long long final_sum = ans * (ans + 1) / 2;
        while ((final_sum - target) % 2 != 0) {
            ans++;
            final_sum += ans;
        }
        
        return ans;
    }
};
