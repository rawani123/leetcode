class Solution {
public:
    int findMax(vector<int> &arr){
        int n=arr.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i]);
        }
        return maxi;
    }
    long calculateTotalHours(vector<int> &arr,int hourly){
        long totalHr=0;
        for(int i=0;i<arr.size();i++){
            totalHr += (arr[i] + hourly - 1) / hourly;
        }
        return totalHr;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=findMax(piles);
        while(low<=high){
            int mid=(low+high)/2;
            long totalHrs=calculateTotalHours(piles,mid);
            if(totalHrs<=h){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};