using namespace std;
class Solution {
public:
    int carFleet(int target, vector<int>& positions, vector<int>& speeds) {
        // Cars - a new array
        vector <pair<int,int>> cars (positions.size());
        for (int i = 0; i < cars.size(); i++) {
            cars[i].first = positions[i];
            cars[i].second = speeds[i];
        }
        // Sort descending (greatest elements at start)
        sort(cars.begin(), cars.end(), greater<pair<int,int>>());
        // Calc time to target per car
        // faster ones at a earlier position forms fleet with slower ones in further position
        stack<double> fleets;
        for (auto [position, speed]: cars) {
            double time = (target - position) / static_cast<double>(speed);
            // If no fleet exists yet or time to target slower than first fleet
            // => new fleet
            if (!fleets.empty() && time <= fleets.top()) continue;
            fleets.push(time);
        }
        return fleets.size();
    }
};
