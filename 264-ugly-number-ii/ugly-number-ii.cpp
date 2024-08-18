#include <queue>
#include <unordered_set>

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0) return 0;  // Base case
        
        std::priority_queue<long, std::vector<long>, std::greater<long>> minHeap;
        std::unordered_set<long> visited;
        
        minHeap.push(1);
        visited.insert(1);
        
        long uglyNumber = 1;
        for (int i = 1; i < n; ++i) {
            uglyNumber = minHeap.top();
            minHeap.pop();
            
            if (visited.find(uglyNumber * 2) == visited.end()) {
                minHeap.push(uglyNumber * 2);
                visited.insert(uglyNumber * 2);
            }
            if (visited.find(uglyNumber * 3) == visited.end()) {
                minHeap.push(uglyNumber * 3);
                visited.insert(uglyNumber * 3);
            }
            if (visited.find(uglyNumber * 5) == visited.end()) {
                minHeap.push(uglyNumber * 5);
                visited.insert(uglyNumber * 5);
            }
        }
        
        return minHeap.top();  // The nth ugly number
    }
};
