class Solution {
public:
    void sortColors(vector<int>& a) {
        int lo=0,mid=0,hi = a.size()-1;
        while(hi>=mid){
            if(a[mid] == 1)
                mid++;
            else if(a[mid] == 0){
                swap(a[lo],a[mid]);
                mid++;
                lo++;
            }
            else if(a[mid] == 2){
                swap(a[mid],a[hi]);
                hi--;
            }
        }
    }
};