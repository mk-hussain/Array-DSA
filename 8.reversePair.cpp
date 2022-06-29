class Solution {
public:
    int merge(vector<int> &a,int l,int r,int mid,vector<int> &temp){
        int count = 0;
        int i = l,j;
        for(j = mid+1;j<=r;j++){
            while(i<=mid && a[i] <= 2ll*a[j])
                i++;
            count += (mid-i+1);
        }
        i = l,j=mid+1;
        for(int k = l;k<=r;k++){
            if(j==r+1 || (i<=mid && a[i] < a[j])){
                temp[k] = a[i++];
            }
            else{
                temp[k] = a[j++];
            }
        }
        
        for(int k = l;k<=r;k++)
            a[k] = temp[k];
        
        return count;
    }
    int mergesort(vector<int> &a,int l,int r,vector<int> &temp){
        if(r-l+1 == 1) return 0;
        int count = 0;
        int mid = (l+r)/2;
        count += mergesort(a,l,mid,temp);
        count += mergesort(a,mid+1,r,temp);
        count += merge(a,l,r,mid,temp);
        return count;
    }
    int reversePairs(vector<int>& a) {
        int n = a.size();
        vector<int> temp(n);
        return mergesort(a,0,n-1,temp);
    }
};