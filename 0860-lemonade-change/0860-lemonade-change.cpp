class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f=0, t=0, tw=0;
        for(int i=0; i<bills.size(); i++){
            if(bills[i]==5)f++;
            if(bills[i]==10){
                if(f){
                    f--;
                    t++;
                }
                else return false;
            }
           if(bills[i]==20){
            if(f&&t){
                f--;
                t--;
                tw++;
            }
           else if(f>=3){
                f-=3;
            }
            else return false;
           }
        }
        return true;
    }
};