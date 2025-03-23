class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
      
        int n = nums.size();
        int count = 0;

        // Iterate over all possible starting points
        for (int i = 0; i < n; i++) {
            int sum = 0; // Reset sum for each new subarray

            // Iterate over all possible ending points
            for (int j = i; j < n; j++) {
                sum += nums[j]; // Add current element to sum
                
                if (sum == goal) {
                    count++; // Increment count if sum equals goal
                }
            }
        }
        return count;
    }
};