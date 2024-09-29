class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> heap;
        for(int i=0;i<nums.size();i++){
            heap.push(nums[i]);
        }
        int f=k-1;
        while(f>0){
            heap.pop();
            f--;
        }
        return heap.top();
    }
};