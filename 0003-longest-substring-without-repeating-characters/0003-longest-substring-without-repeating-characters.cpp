class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)return 0;
        int n=s.size();
        int maxlen= INT_MIN;
        int l=0, r=0, len=0;  
        vector<int>hash(256,-1);
       while(r<n){
        if(hash[s[r]]!=-1){
            if(l<=s[r]){
                l=hash[s[r]]+1;
            }
        }
     len= r-l+1;
     maxlen= max(len,maxlen);
     hash[s[r]]=r;
     r++;
       }
       return maxlen;
    }
};