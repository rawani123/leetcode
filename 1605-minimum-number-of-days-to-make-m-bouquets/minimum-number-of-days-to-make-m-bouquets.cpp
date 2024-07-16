class Solution {
public:
    bool possible(vector<int>& bloomDay, int day, int m, int k) {
        int count = 0;
        int bouquets = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                count++;
                if (count == k) {
                    bouquets++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }
        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = (long long)m * k;
        if (val > bloomDay.size()) return -1;  // Note the change here

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (possible(bloomDay, mid, m, k)){
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};