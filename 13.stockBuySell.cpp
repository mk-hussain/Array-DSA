class Solution {
    // try running this on stock price graph
public:
    int maxProfit(vector<int>& prices) {
        int l=prices[0],r=prices[0],maxProfit = 0;
        for(auto p : prices){
            if(p < l){
                l = p;
                r=p;
            }
            else{
                r = p;
                maxProfit = max(maxProfit,r-l);
            }
        }
        return maxProfit;
        
    }
};