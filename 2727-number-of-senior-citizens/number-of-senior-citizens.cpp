class Solution {
public:
    int countSeniors(vector<string>& details) {
    int count = 0;
    for (const string& detail : details) {
       
        string age_str = detail.substr(11, 2);
        
        int age = stoi(age_str);
    
        if (age > 60) {
            count += 1;
        }
    }
    return count;
}
};