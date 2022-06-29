class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int ind1=-1, n = a.size(),ind2;
        // a[ind1] < a[ind1+1]
        for(int i= n-2 ; i>=0 ;i--){
            if(a[i] < a[i+1]){
                ind1 = i;
                break;
            }
        }
        if(ind1 == -1){// decreasing order -> reverse 1st permutation
            reverse(a.begin(),a.end());
            return;
        }
        // search for rightmost ind2 st. a[ind1] < a[ind2]
        for(int i=n-1;i>=0;i--){
            if(a[i] > a[ind1]) {
                ind2 = i;
                break;
            }
        }
        // swap ind1 and ind2
        swap(a[ind1],a[ind2]);
        // reverse everything from ind1 + 1 till last
        reverse(a.begin() + ind1+1,a.end());
    }
};