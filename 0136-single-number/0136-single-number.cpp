class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
unordered_map<int, int> numCount;
    
    // Count occurrences of each number
    for (int num : nums) {
        numCount[num]++;
    }
    
    // Find the number that appears only once
    for (auto& pair : numCount) {
        if (pair.second == 1) {
            return pair.first;
        }
    }
    
    return -1; // This line should never be reached given the problem constraints
    }
};