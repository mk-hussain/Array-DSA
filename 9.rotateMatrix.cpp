class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int n = m.size();
        // transpose
        for(int i=0;i<n;i++)
            for(int j=0;j<i;j++)
                swap(m[i][j],m[j][i]);
        
        // reverse every row
        for(int i=0;i<n;i++){
            reverse(m[i].begin(),m[i].end());
        }
    }
};