class Solution {
public:
    int romanToInt(string s) {
       map<char,int> mpp={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}} ;
    
    int index=0;
    int sum=0;
    while(index<s.size()){
        if(mpp[s[index]]<mpp[s[index+1]]){
            sum-=mpp[s[index]];
            
        }else{
            sum+=mpp[s[index]];
        }
        index++;
    }
    return sum;

    };

};