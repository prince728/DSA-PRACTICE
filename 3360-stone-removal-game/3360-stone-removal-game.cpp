class Solution {
public:
    bool canAliceWin(int n) {
        bool AliceTurn =0;
        int count=10;
        
        while(n>=count){
            n-=count;
            AliceTurn= !AliceTurn;
            count--;
        }
        return AliceTurn;
    }
};