class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int goal) {
        return (numSubarray(nums,goal)-numSubarray(nums, goal-1));
    }
      int numSubarray(vector<int>& nums, int goal) {
      int l=0,r=0,cnt=0;
      long long sum=0;
      while(r<nums.size()){
       sum+=nums[r]%2;
       while(sum>goal && l<=r){
       sum=sum-nums[l]%2;
       l++;
       }
        cnt+=r-l+1;
        r++;
      }
      return cnt;
    }
};
    
