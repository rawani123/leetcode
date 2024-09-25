class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    int count1=0,count2=0;
    int el1=0,el2=1;  
    for(int i=0;i<nums.size();i++){
        if(count1==0 && nums[i]!=el2){ 
            count1=1;     
            el1=nums[i]; 
        }
        else if(count2==0 && nums[i]!=el1){
            count2=1; 
            el2=nums[i]; 
        }else if(el1==nums[i]){
            count1++; 
        }
        else if(el2==nums[i]){
            count2++;
        }
        else{  
            count1--;
            count2--;
        }
    }

    vector<int> ans;
    count1=0;   
    count2=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==el1) count1++; 
        if(nums[i]==el2) count2++; 
    }
    int maxtimes=(int)(nums.size()/3)+1;

    if(count1>=maxtimes) ans.push_back(el1);
    if(count2>=maxtimes) ans.push_back(el2);

    return ans;
}
};