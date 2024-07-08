class Solution {
public:

    void lpsFind(vector<int>&ans,string s){
        
	    int pre=0,suf=1;
	    while(suf<s.size()){
	        if(s[pre]==s[suf]){
	            ans[suf]=pre+1;
	            pre++,suf++;
	        }else{
	            if(pre==0){
	                ans[suf]=0;
	                suf++;
	            }else{
	                pre=ans[pre-1];
	            }
	        }
	    }
    }
    int strStr(string haystack, string needle) {
        vector<int> ans(needle.size(),0);
        lpsFind(ans,needle);
        int first=0,second=0;
        while(first<haystack.size() && second<needle.size()){
            if(haystack[first]== needle[second]){
                first++;
                second++;
            }
            else{
                if(second==0){
                    first++;
                }
                else{
                    second=ans[second-1];
                }
            }
        }
        if(second==needle.size()){
            return first-second;
        }
        return -1;

    }
};