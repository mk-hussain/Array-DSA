#include <bits/stdc++.h> 
long long merge(long long int* a,int l,int r,int mid,int* temp){
    int i = l,j=mid+1;
    long long invcount = 0;
    for(int k = l;k<=r;k++){
        if(j == r+1 || (i<=mid && a[i]<=a[j])){
            temp[k]=a[i++];
        }
        else{// a[i] strictly > a[j]
            temp[k]=a[j++];
            invcount += (mid - i +1);
        }
    }
    for(int k=l;k<=r;k++){
        a[k] = temp[k];
    }
    return invcount;
}
long long mergesort(long long int* a,int l,int r,int* temp){
    if(r-l+1 == 1)
        return 0;// no inversion with single element
    long long invcount = 0;
    int mid = (l+r)/2;
    invcount += mergesort(a,l,mid,temp);
    invcount += mergesort(a,mid+1,r,temp);
    invcount += merge(a,l,r,mid,temp);
    return invcount;
}
long long getInversions(long long *a, int n){
    int* temp = new int[n];
    long long int invcount = 0;
    invcount += mergesort(a,0,n-1,temp);
    return invcount;
}