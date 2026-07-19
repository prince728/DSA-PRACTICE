class Solution {
public:
    int power(int a,int digit){
        a%=1337;
        int ans=1;
        for(int i=0;i<digit;i++){
            ans = (ans*a)%1337;
        }
        return ans;
    }

        int superPow(int a, vector<int>& b) {

        if (b.empty())
            return 1;
        if (a == 1 || a == 0)
            return a;

        int MOD = 1337;

        int last_digit = b.back();
        b.pop_back();

        int part1 = power(a, last_digit);
        int part2 = power(superPow(a, b), 10);

        return (part1 * part2) % MOD;
    }
};