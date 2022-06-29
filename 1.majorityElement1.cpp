class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0,element ;
        for(auto num : nums){
            if(count == 0){
                element = num;
            }
            if(num == element)
                count++;
            else
                count--;
        }
        return element;
    }
};