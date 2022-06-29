class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int n = mat.size() , m = mat[0].size();
        int lo = 0, hi = m*n-1 , mid;
        bool found = false;
        while(hi >= lo){
            mid = (lo+hi)/2;
            int i = mid/m , j= mid%m;
            if(mat[i][j] < t){
                lo=mid+1;
            }
            else if(mat[i][j] > t){
                hi=mid-1;
            }
            else{
                found = true;
                break;
            }
        }
        if(found)
            return true;
        else
            return false;
    }
};