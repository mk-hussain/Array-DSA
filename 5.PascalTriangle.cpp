// variation 1:- given a n print all 1 to n row of pascal triangle
class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        for(int i=1;i<=n;i++){
            vector<int> v;
            for(int j=1;j<=i;j++){
                if(j==1 || j==i){// 1st and last of every row = 1
                    v.push_back(1);
                }
                else{
                    v.push_back(ans[i-2][j-1]+ans[i-2][j-2]); // sum of top and top left element
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};

// variation 2:- given i,j print ith row and jth column of pascal triangle
// i th row represent (a+b)^(i-1) -> i-1C0 , i-1C1 ..... i-1 C i-1
// ith row and jth column ans = (i-1) C (j-1)