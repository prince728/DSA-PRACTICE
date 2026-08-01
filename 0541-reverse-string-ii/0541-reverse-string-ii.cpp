class Solution {
public:
    string reverseStr(string s, int k) {
        int index=0;
        while(index<s.size()){
            int first=index;
            int second=min(index+k-1,(int)s.size()-1);
            while(first<second){
                swap(s[first],s[second]);
                first++;
                second--;
            }
        
            index += 2 * k;
        }
        return s;
    }
};