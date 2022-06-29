// n^2 solution -> brute
class Solution{
    public:
    int maxLen(vector<int>&a, int n)
    {   
        int maxi = 0;
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum+=a[j];
                if(sum == 0){
                    maxi=max(maxi,j-i+1);
                }
            }
        }
        return maxi;
    }
};

// ~O(N) TC and O(N) SC
class Solution{
    public:
    int maxLen(vector<int>&a, int n){
        unordered_map<int,int> m;
        int sum = 0,maxi = 0;
        for(int i=0;i<n;i++){
            sum+=a[i];
            if(sum == 0) maxi = i+1;
            else if(m.find(sum) == m.end()){
                m[sum] = i;
            }
            else{
                maxi = max(maxi,i-m[sum]);
            }
        }
        return maxi;
    }
};