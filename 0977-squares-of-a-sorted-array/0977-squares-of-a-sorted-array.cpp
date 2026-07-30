class Solution {
public:
    vector<int> sortedSquares(vector<int>& arr) {
        int n=arr.size(),left=0,right =n-1;
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            int left_square =arr[left]*arr[left];
            int right_square =arr[right]*arr[right];

            if(left_square> right_square){
                ans[i]=left_square;
                left++;
            }
            else{
                ans[i]=right_square;
                right--;
            }
        }
        return ans;
    }
};