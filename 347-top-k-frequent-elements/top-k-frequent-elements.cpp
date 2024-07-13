class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        
        auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second; 
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minHeap(cmp);
        
        for (auto& entry : freq) {
            minHeap.push(entry);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
       
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().first);
            minHeap.pop();
        }
        
        return result;
    }
};