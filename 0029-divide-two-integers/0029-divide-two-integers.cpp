class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor)return 1;
        bool sign=true;
        if(dividend>=0 && divisor<0)sign=false;
        if(dividend<=0 && divisor>0)sign =false;
       long n = abs((long)dividend);
        long d = abs((long)divisor);
         long q=0;
         while(n>=d){
            int c=0;
            while(n>=(d<<(c+1))){
                c+=1;
            }
            q+=1<<c;
            n-=(d<<c);

         }
         if(q==(1<<31)&& sign)return INT_MAX;
         if(q==(1<<31)&& !sign)return INT_MIN;
         return sign?q:-q;
        
    }
};