class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()< 3) return 0;
        int topIndex=0;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]==arr[i+1]) return 0;
            if(arr[topIndex]<arr[i]) topIndex=i;
        }
        if(topIndex==0 || topIndex==arr.size()-1) return 0;

        for(int i=topIndex;i<arr.size()-1;i++){
            if(arr[i]<arr[i+1]) return 0;
        }
        for(int i=topIndex;i>0;i--){
            if(arr[i]<arr[i-1]) return 0;
        }

        return 1;

    }
};