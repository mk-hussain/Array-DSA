// sorting approach maybe interviewer will be unhappy
class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        if(a.size() == 0)
            return 0;
        sort(a.begin(),a.end());
        int maxi = 1,last = a[0],ans=1;
        for(auto num : a){
            if(num == last)
                continue;
            if(num == last +1){
                ans++;
                maxi = max(maxi,ans);
            }
            else{
                ans=1;
            }
            last =num;
        }
        return maxi;
    }
};

// sorting approach maybe interviewer will be unhappy
class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        if(a.size() == 0) return 0;
        unordered_set<int> s;// O(1) insertion and access
        for(auto num : a)
            s.insert(num);
        int max_streak = 0;
        for(auto num : a){
            if(s.find(num-1) == s.end()){// this is the minimal element of streak starting at num
                int count = 0;
                do{
                    count++;
                }while(s.find(++num) != s.end());
                max_streak = max(max_streak,count);
            }
        }
        return max_streak;   
    }
};