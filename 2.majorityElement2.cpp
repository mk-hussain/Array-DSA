class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // you can never have more than 2 majority element
        int n = nums.size();
        vector<int> ans;
        int count1=0,count2=0,element1 = INT_MAX ,element2 = INT_MAX;
        for(auto num : nums){
            if(num == element1){
                count1++;
            }
            else if(num == element2){
                count2++;
            }
            else if(count1 == 0){
                element1 = num;
                count1 = 1;
            }
            else if(count2 == 0){
                element2 = num;
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        count1=0;
        count2=0;
        for(auto num : nums){
            if(element1 == num)
                count1++;
            if(element2 == num)
                count2++;
        }
        if(count1 > n/3)
            ans.push_back(element1);
        if(count2 > n/3)
            ans.push_back(element2);
        return ans;
    }
};