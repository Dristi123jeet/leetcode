class Solution {
public:
    vector<vector<int>> subsets(vector<int>& arr) {
        int n = arr.size();
        int totalSubsets = (1 << n); // 2^n subsets
        vector<vector<int>> subs; // Store all subsets
        
        for (int num = 0; num < totalSubsets; num++) {
            vector<int> subset; // Store current subset
            for (int j = 0; j < n; j++) {
                if (num & (1 << j)) subset.push_back(arr[j]); // Pick elements based on bits
            }
            subs.push_back(subset); // Add current subset to result
        }
        return subs;
    }
};