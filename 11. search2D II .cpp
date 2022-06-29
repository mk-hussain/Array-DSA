class Solution {
public:
    // row and column wise sorted matrix
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size() , m = matrix[0].size() ;
        int i=0,j=m-1; // top right moves -> down and left
        while(i<n && j>=0 && matrix[i][j] != target){
            if(matrix[i][j] > target)
                j--;
            else 
                i++;
        }
        // check out of bound
        if(i>= n || j <0)
            return false;
        else
            return true;
    }
};