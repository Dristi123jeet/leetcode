class Solution {
public:
vector<int> prevs(vector<int>&nums){
     int n = nums.size();
        vector<int> pse(n);  // Initialize with correct size
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) st.pop();
            pse[i] = st.empty() ? -1 : st.top();  // Store index, not value
            st.push(i);
        }
        return pse;
    }

    vector<int> nexts(vector<int>& nums) {
        int n = nums.size();
        vector<int> nse(n);  // Initialize with correct size
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            nse[i] = st.empty() ? n : st.top();  // Store index, not value
            st.push(i);
        }
        return nse;
    }

    int sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();
        int mod = 1e9 + 7;
        vector<int> left = prevs(nums);
        vector<int> right = nexts(nums);

        long long total = 0;
        for (int i = 0; i < n; i++) {
            long long leftCount = i - left[i];
            long long rightCount = right[i] - i;
            total = (total + (leftCount * rightCount  * nums[i] *1ll)) % mod;
        }
        return total;
    }
};