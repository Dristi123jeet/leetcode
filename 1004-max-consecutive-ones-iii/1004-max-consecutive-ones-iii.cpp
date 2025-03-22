class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int maxlen= 0;
        for(int i=0; i<n; i++){
            int c=0;
            for(int j=i; j<n; j++){
            if(nums[j]==0)c++;
            if(c<=k){
            maxlen= max(maxlen,j-i+1);
            }
            else break;
            }
        }
        return maxlen;
    }
};