class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
     map<int,string> mpp;
     for(int i=0;i<names.size();i++){
        mpp[heights[i]]=names[i];
     }   
     vector<string> ans;
     auto it=mpp.end();
     it--;
     while(it!=mpp.begin()){
        ans.push_back(it->second);
        it--;
     }
     ans.push_back(it->second);
     return ans;
    }
};