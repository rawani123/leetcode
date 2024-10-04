class Solution {
public:
    int maxProfit(vector<int>& prices) {
   
    int min_price = INT_MAX;
    int max_profit = 0;

    
    for (int price : prices) {
        
        min_price=min(min_price,price);
       
        int potential_profit = price - min_price;
        max_profit=max(max_profit,potential_profit);
    }

    return max_profit;
}

};