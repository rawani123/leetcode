#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dp;

    Solution() : dp(46, -1) {} 
    int climbStairs(int n) {
        if (dp[n] != -1) return dp[n];
        if (n <= 2) {
            return dp[n] = n;
        }
        return dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
    }
};
