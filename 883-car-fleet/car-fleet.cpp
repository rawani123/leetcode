#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> cars(n);

        // Combine position and speed into pairs and sort by position in descending order
        for (int i = 0; i < n; ++i) {
            cars[i] = {position[i], speed[i]};
        }
        sort(cars.begin(), cars.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });

        // Calculate time to reach the destination
        vector<double> time(n);
        for (int i = 0; i < n; ++i) {
            time[i] = (double)(target - cars[i].first) / cars[i].second;
        }

        // Count fleets
        int fleets = 0;
        double lastTime = 0.0;
        for (int i = 0; i < n; ++i) {
            if (time[i] > lastTime) {
                // New fleet
                ++fleets;
                lastTime = time[i];
            }
        }

        return fleets;
    }
};
