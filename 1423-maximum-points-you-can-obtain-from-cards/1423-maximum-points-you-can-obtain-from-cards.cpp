class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int ls=0,  rs=0, maxs=0;
        for(int i=0; i<k; i++){
            ls+=card[i];
            maxs=ls;
        }
        int r=card.size()-1;
        for(int i= k-1; i>=0; i--){
            ls-=card[i];
            rs+=card[r];
            r--;
            maxs= max(maxs,(ls+rs));
        }
        return maxs;
    }
};