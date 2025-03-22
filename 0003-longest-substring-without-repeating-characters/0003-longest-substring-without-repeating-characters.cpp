class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)return 0;
        int maxlen= INT_MIN;
        for(int i=0; i<s.size(); i++){
             unordered_set<int>set;
            for(int j=i; j<s.size(); j++){
                if(set.find(s[j])!= set.end())break;
                
                set.insert(s[j]);
                maxlen= max(maxlen, j-i+1);
            }
        }
        return maxlen;
    }
};