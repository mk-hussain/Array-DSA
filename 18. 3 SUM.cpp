class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        vector<vector<int>> ans;
        int n = a.size();
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++){
            // if a[i] = a[i-1] then whatever triplet a[i] will get is already covered by a[i-1]
            if(i==0 || a[i] != a[i-1]){
                int lo = i+1,hi=n-1;
                while(hi>lo){
                    int sum = a[i]+a[lo]+a[hi];
                    if(sum < 0) lo++;
                    
                    else if(sum > 0) hi--;
                    
                    else{
                        vector<int> triplet(3);
                        triplet[0] = a[i];
                        triplet[1] = a[lo];
                        triplet[2] = a[hi];// a[i]<=a[lo]<=a[hi] assured by sorting
                        ans.push_back(triplet);
                        while(lo+1 < n &&a[lo] == a[lo+1]) lo++; // ignore all same a[lo]
                        while(hi-1 >= 0 && a[hi] == a[hi-1]) hi--;// ignore all same a[hi]
                        lo++;
                        hi--;
                    }
                }
            }
        }
        return ans;
    }
};