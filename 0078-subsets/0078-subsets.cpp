class Solution {
public:
    void helper(int i, vector<int>& arr, vector<int>& curr, vector<vector<int>>& ans) {
        if (i == arr.size()) {
            ans.push_back(curr);
            return;
        }

        // Exclude current element
        helper(i + 1, arr, curr, ans);

        // Include current element
        curr.push_back(arr[i]);
        helper(i + 1, arr, curr, ans);
        curr.pop_back(); // backtrack
    }

    vector<vector<int>> subsets(vector<int>& arr) {
        vector<vector<int>> anss;
        vector<int> curr;
        helper(0, arr, curr, anss);
        return anss;
    }
};
