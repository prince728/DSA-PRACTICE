class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        int first = 0, last = citations.size()-1;
        while (first <= last) {
            int mid = first + (last - first) / 2;
            if (citations[mid] >= size - mid)
                last = mid - 1;
            else
                first = mid + 1;
        }

        return size - first;
    }
};