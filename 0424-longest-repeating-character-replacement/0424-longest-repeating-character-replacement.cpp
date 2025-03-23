class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxlen=0;
        int l=0, r=0, f=0;
        int n= s.size();
        map<char, int>mpp;
        while(r<n){
            mpp[s[r]]++;
          f= max(f,mpp[s[r]]);
        if((r-l+1)-f>k){
            
             mpp[s[l]]--;
            if(mpp[s[l]]==0)mpp.erase(s[l]);
            l++;
          }
          maxlen= max(maxlen, r-l+1);
           r++;
        }
        return maxlen;
    }
};