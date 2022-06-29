// summation and summation will fail because of overflow (sigma i^2) exceed long long
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int a=0;
    for(int i=0;i<A.size();i++){
        a=a^((i+1)^A[i]);
    }
    // a-> X^Y
    int j=0;
    while((a&(1<<j)) == 0){
        j++;
    }
    // j-> index of set bit in X^Y
    // put all 1.. n and a[i] in bucket1 if its jth bit is set
    int bucket1=0,bucket2=0;
    for(int i=0;i<A.size();i++){
        if(((i+1)&(1<<j))){
            bucket1^=(i+1);
        }
        else{
            bucket2^=(i+1);
        }
        if((A[i]&(1<<j))){
            bucket1^=A[i];
        }
        else{
            bucket2^=A[i];
        }
    }
    vector<int> ans(2);
    ans[0]=bucket1;
    ans[1]=bucket2;
    bool inorder=false;
    for(int i=0;i<A.size();i++){
        if(A[i]==ans[0]){
            inorder = true;
            break;
        }
    }
    if(inorder){
        return ans;
    }
    else{
        swap(ans[0],ans[1]);
        return ans;
    }
}
