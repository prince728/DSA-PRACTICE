class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start,
                                int destination) {
        int clockwise = 0, antiClockwise = 0, index = start,
            n = distance.size();

        while (index % n != destination)
            clockwise += distance[index++ % n];

        while (index % n != start)
            antiClockwise += distance[index++ % n];

        return min(clockwise, antiClockwise);
    }
};