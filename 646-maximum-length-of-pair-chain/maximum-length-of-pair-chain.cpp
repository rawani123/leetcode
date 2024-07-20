class Solution {
public:
    struct Data{
        int start=0;
        int end=0;
        int pos=0;
         Data(int s, int e, int p) : start(s), end(e), pos(p) {}
    };
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<Data> arr;
        for (int i = 0; i < pairs.size(); ++i) {
            arr.emplace_back(pairs[i][0], pairs[i][1], i + 1);
        }
        sort(begin(pairs),end(pairs),[&](const vector<int> &v1 , const vector<int> &v2)->bool{
           return v1[1] < v2[1] ; 
        });
        
        int prevMeeting = 0 , maxi = 1 ;
        for(int i = 1 ; i < pairs.size() ; ++i){
            if(pairs[i][0] > pairs[prevMeeting][1]) prevMeeting = i , ++maxi ;
        }
        return maxi ;
    }
};