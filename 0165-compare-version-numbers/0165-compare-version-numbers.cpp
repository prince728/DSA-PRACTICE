class Solution {
public:
    int compareVersion(string version1, string version2) {
        int first = 0, second = 0;
        int n1 = version1.size(), n2 = version2.size();
        long long v1 = 0, v2 = 0;

        while (first < n1 || second < n2) {

            while (first < version1.size() && version1[first] != '.') {
                v1 = v1 * 10 + version1[first] - '0';
                first++;
            }

            while (second < version2.size() && version2[second] != '.') {
                v2 = v2 * 10 + version2[second] - '0';
                second++;
            }

            if (v1 < v2)
                return -1;
            if (v1 > v2)
                return 1;

            v1=0,v2=0;
            first++,second++;
        }

        return 0;
    }
};