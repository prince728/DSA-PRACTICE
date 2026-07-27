class Solution {
public:
    bool checkPerfectNumber(int n) {
        if((n%2)) return 0;
        int sum=0;
        for(int i=1;i<=n/2;i++){
            int div = n/i;
            if(n == i*div) sum+=i;
        }

        return sum==n;
    }
};