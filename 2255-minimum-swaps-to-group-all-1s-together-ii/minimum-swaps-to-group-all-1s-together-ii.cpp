class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int totalOnes = count(nums.begin(), nums.end(), 1);
        
        if (totalOnes == 0) {
            return 0;
        }
        
        vector<int> extendedNums(nums.begin(), nums.end());
        extendedNums.insert(extendedNums.end(), nums.begin(), nums.end());
        
        int currentOnes = 0;
        for (int i = 0; i < totalOnes; ++i) {
            if (extendedNums[i] == 1) {
                currentOnes++;
            }
        }
        
        int maxOnesInWindow = currentOnes;
        
        for (int i = totalOnes; i < 2 * n; ++i) {
            if (extendedNums[i] == 1) {
                currentOnes++;
            }
            if (extendedNums[i - totalOnes] == 1) {
                currentOnes--;
            }
            maxOnesInWindow = max(maxOnesInWindow, currentOnes);
        }
        
        return totalOnes - maxOnesInWindow;
    }
};
