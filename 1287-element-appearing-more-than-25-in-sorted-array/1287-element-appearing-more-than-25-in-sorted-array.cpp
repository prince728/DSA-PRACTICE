class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();

        if(n<3) return arr[0];

        double cutOff = (double)n/4;
        int freq=1;

        for(int i=1;i<n;i++){
            if(arr[i]==arr[i-1]) freq++;
            else freq=1;
            if(freq > cutOff) return arr[i];
        }
        return -1;
    }
};