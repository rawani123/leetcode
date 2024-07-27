
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }
        
        int x = nums1.size();
        int y = nums2.size();
        int low = 0, high = x;
        
        while (low <= high) {
            int partitionX = (low + high) / 2;
            int partitionY = (x + y + 1) / 2 - partitionX;
            
            int maxX = (partitionX == 0) ? numeric_limits<int>::min() : nums1[partitionX - 1];
            int minX = (partitionX == x) ? numeric_limits<int>::max() : nums1[partitionX];
            
            int maxY = (partitionY == 0) ? numeric_limits<int>::min() : nums2[partitionY - 1];
            int minY = (partitionY == y) ? numeric_limits<int>::max() : nums2[partitionY];
            
            if (maxX <= minY && maxY <= minX) {
                if ((x + y) % 2 == 0) {
                    return (max(maxX, maxY) + min(minX, minY)) / 2.0;
                } else {
                    return max(maxX, maxY);
                }
            } else if (maxX > minY) {
                high = partitionX - 1;
            } else {
                low = partitionX + 1;
            }
        }
        
        throw invalid_argument("Input arrays are not sorted or valid.");
    }
};