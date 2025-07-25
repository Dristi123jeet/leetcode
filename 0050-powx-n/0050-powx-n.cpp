class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        long long nn= n;
        if(n<0)nn= -1*nn;
        while(nn){
            if(nn%2==0){
                x=x*x;
                nn=nn/2;
            }
            else{
                ans=ans*x;
                nn=nn-1;
            }
        }
        double nans = (double)(1.0)/ (double)(ans);
        if(n<0)return nans;
        return ans;
        
    }
};