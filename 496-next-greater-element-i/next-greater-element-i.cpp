class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> next_greater_map;
        stack<int> stack;

        // Traverse nums2 to find next greater elements


        for (int i = nums2.size() - 1; i >= 0; --i) {
            while (!stack.empty() && stack.top()  <=  nums2[i]) {
                stack.pop();
            }

            if (!stack.empty()) {
                next_greater_map[nums2[i]] = stack.top();
            } else {
                next_greater_map[nums2[i]] = -1; 
            }
            stack.push(nums2[i]); 
        }

        // Prepare result for nums1
        vector<int> result(nums1.size());
        for (int i = 0; i < nums1.size(); ++i) {
            result[i] = next_greater_map[nums1[i]];
        }

        return result;
    }
    
};