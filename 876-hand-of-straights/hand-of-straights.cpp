class Solution {
public:
    bool isNStraightHand(std::vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        unordered_map<int, int> count;
        for (int card : hand) {
            count[card]++;
        }
        sort(hand.begin(), hand.end()); 
        for (int card : hand) {  
            if (count[card] == 0) continue;             
            for (int i = 0; i < groupSize; ++i) {
                int currCard = card + i; 
                if (count[currCard] == 0) {
                    return false; 
                }
                count[currCard]--;
            }
        }
        return true;
    }
};
