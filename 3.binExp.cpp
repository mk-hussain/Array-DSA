class Solution {
public:
    double binExp(double x,long long int n){
        double ans= 1;
        while(n){
            if(n&1){
                ans=ans*x;
            }
            x=x*x;
            n=(n>>1);
        }
        return ans;
    }
    double myPow(double x, int n) {
        long long num=n;
        if(num >= 0){
            return binExp(x,num);
        }
        else{
            return 1/(binExp(x,-num));
        }
    }
};
/* 
important point:-
INT_MIN = -2147483648
INT_MAX = +2147483647
so -(INT_MIN) cannto be stored
in signed 32 bit integer so take long long instead
*/