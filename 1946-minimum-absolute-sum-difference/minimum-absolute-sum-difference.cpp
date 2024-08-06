class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
       
        const int MOD = 1e9 + 7;

        vector<int> sortedNums(nums1);
        sort(sortedNums.begin(), sortedNums.end());

        int sumOfDifferences = 0;
        int size = nums1.size();
        for (int i = 0; i < size; ++i) {
            sumOfDifferences = (sumOfDifferences + abs(nums1[i] - nums2[i])) % MOD;
        }
      
       
        int maxImprovement = 0;

        for (int i = 0; i < size; ++i) {

            int currentDiff = abs(nums1[i] - nums2[i]);

            int improvedDiff = INT_MAX;

            auto lowerIt = lower_bound(sortedNums.begin(), sortedNums.end(), nums2[i]);

            if (lowerIt != sortedNums.end()) {
                improvedDiff = min(improvedDiff, abs(*lowerIt - nums2[i]));
            }
            if (lowerIt != sortedNums.begin()) {
                improvedDiff = min(improvedDiff, abs(*prev(lowerIt) - nums2[i]));
            }
            maxImprovement = max(maxImprovement, currentDiff - improvedDiff);
        }
        return (sumOfDifferences - maxImprovement + MOD) % MOD;
    }
};