class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int, double>> cars;

        for (int i = 0; i < position.size(); i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        // Sort by position from closest to target to farthest
        sort(cars.rbegin(), cars.rend());

        int fleets = 0;
        double prevTime = 0;

        for (auto &car : cars) {

            double currTime = car.second;

            // This car cannot catch the fleet ahead
            if (currTime > prevTime) {
                fleets++;
                prevTime = currTime;
            }
        }

        return fleets;
    }
};