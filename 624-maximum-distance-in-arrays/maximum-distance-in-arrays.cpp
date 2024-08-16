class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int maxDist = 0;
        
        // Initialize with the first array's first and last elements
        int globalMin = arrays[0][0];
        int globalMax = arrays[0].back();
        
        // Start iterating from the second array
        for (int i = 1; i < arrays.size(); ++i) {
            int currentMin = arrays[i][0];
            int currentMax = arrays[i].back();
            
            // Calculate possible max distances using the current array's min and max
            maxDist = max(maxDist, abs(currentMax - globalMin));
            maxDist = max(maxDist, abs(globalMax - currentMin));
            
            // Update the global minimum and maximum with current array's min and max
            globalMin = min(globalMin, currentMin);
            globalMax = max(globalMax, currentMax);
        }
        
        return maxDist;
    }
};
