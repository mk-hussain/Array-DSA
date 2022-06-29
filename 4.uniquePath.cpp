// top down dp/recursion approach  O(N*M) space and time
class Solution {
public:
    int ways(int x,int y,vector<vector<int>> &dp,int m,int n){
        if(x>=m || y >= n)
            return 0;
        if(x==m-1 && y == n-1)
            return 1;
        if(dp[x][y] != -1) return dp[x][y];
        return dp[x][y] = ways(x+1,y,dp,m,n) + ways(x,y+1,dp,m,n);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1)); 
        // dp[i][j] -> no of ways to reach m-1,n-1 from i,j
        return ways(0,0,dp,m,n);
    }
};

// O(MIN(r,c)) time and O(1) space
class Solution {
public:
    int uniquePaths(int r, int c) {
        int n = r-1,m=c-1;
        // ans = (n+m)cn/m
        int s=n+m;
        n=min(n,m);
        // ans=scn
        if(n==0){
            return 1;
        }
        long long int ans=1;
        for(int i=1;i<=n;i++){
            ans=ans*(s-i+1);
            ans=ans/i;
        }
        return ans;
    }
};