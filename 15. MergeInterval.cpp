class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int start=intervals[0][0],end=intervals[0][1];
        for(auto iv : intervals){
            if(iv[0] <= end){
                end=max(end,iv[1]);
            }
            else{
                // disconnected
                ans.push_back({start,end});
                start = iv[0];
                end = iv[1];
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};