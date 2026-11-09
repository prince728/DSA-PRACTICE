class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        vector<int> ans;
        int count = 0;
        for (int i = 0; i < arr.size(); i++)
            if (arr[i] == 1)
                count++;

        if (count % 3 != 0)
            return {-1, -1};

        if (count == 0)
            return {0, (int)arr.size() - 1};

        int k = count / 3, first = -1, second = -1, third = -1, count1 = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 1) {
                count1++;
                if (count1 == 1)
                    first = i;
                if (count1 == k + 1)
                    second = i;
                if (count1 == 2 * k + 1)
                    third = i;
            }
        }

        while (third < arr.size()) {
            if (arr[first] != arr[second] || arr[second] != arr[third]) {
                return {-1, -1};
            }
            first++;
            second++;
            third++;
        }

        return {first - 1, second};
    }
};