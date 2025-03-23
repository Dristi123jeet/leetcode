class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxlen=0;
        int l=0, r=0, f=0;
        int n= s.size();
        map<int, int>mpp;
        while(r<n){
            mpp[s[r]]++;
          f= max(f,mpp[s[r]]);
          int c= (r-l+1)-f;
          if(c>k){
            mpp[s[l]]--;
           
            l++;
          }
          maxlen= max(maxlen, r-l+1);
           r++;
        }
        return maxlen;
    }
};