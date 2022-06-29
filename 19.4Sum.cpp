// set for unique quadruple
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int target) {
        int n = a.size();
        sort(a.begin(),a.end());
        set<vector<int>> s;
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int lo = j+1,hi = n-1;
                while(hi>lo){
                    long long int sum = 1ll*a[i]+a[j]+a[lo]+a[hi];
                    if(sum < target){
                        lo++;
                    }
                    else if(sum > target){
                        hi--;
                    }
                    else{
                        s.insert({a[i],a[j],a[lo++],a[hi--]});
                    }
                }
            }
        }
        for(auto &val : s){
            ans.push_back(val);
        }
        return ans;
    }
};

// no set for unique element

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int target) {
        int n = a.size();
        sort(a.begin(),a.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int lo = j+1,hi = n-1;
                while(hi>lo){
                    long long int sum = 1ll*a[i]+a[j]+a[lo]+a[hi];
                    if(sum < target){
                        lo++;
                    }
                    else if(sum > target){
                        hi--;
                    }
                    else{
                        vector<int> quad = {a[i],a[j],a[lo],a[hi]};
                        ans.push_back(quad);
                        while(lo < n && a[lo]==quad[2]) lo++;
                        while(hi >=0 && a[hi]==quad[3]) hi--;
                    }
                }
                while(j+1 < n && a[j+1] == a[j]) j++;
            }
            while(i+1 < n && a[i+1] == a[i]) i++; // additional i++ and j++ in loop remember 
        }
        
        return ans;
    }
};

// a,b,c,d