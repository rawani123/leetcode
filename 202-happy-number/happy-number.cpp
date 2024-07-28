class Solution {
public:
   bool isHappy(int n) {
        auto getNext = [](int number) {  
            int totalSum = 0;
            while (number > 0) {
                int digit = number % 10; 
                totalSum += digit * digit; 
                number /= 10; 
            }
            return totalSum;
        };

        unordered_set<int> seen;   
        
        while (n != 1 && seen.find(n) == seen.end()) {   
            seen.insert(n); 
            n = getNext(n);
        }

        return n == 1;
    }
};