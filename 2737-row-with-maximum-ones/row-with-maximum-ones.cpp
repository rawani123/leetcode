class Solution {
public:
    int countOnes(vector<int>& row) {
        int count = 0;
        for (int num : row) {
            if (num == 1) {
                count++;
            }
        }
        return count;
    }

    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxOnes = -1;
        int rowIndex = -1;

        for (int i = 0; i < mat.size(); ++i) {
            int count = countOnes(mat[i]);
            if (count > maxOnes) {
                maxOnes = count;
                rowIndex = i;
            }
        }

        return {rowIndex, maxOnes};
    }
};


