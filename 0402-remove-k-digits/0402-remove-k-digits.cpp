
       class Solution {
public:
    string removeKdigits(string s, int k) {
        list<char> ans;  // Use list<char> to maintain order
        
        for (char c : s) {
            while (!ans.empty() && k > 0 && ans.back() > c) {
                ans.pop_back();
                k--;
            }
            ans.push_back(c);
        }

        // Remove remaining `k` digits if needed
        while (k > 0 && !ans.empty()) {
            ans.pop_back();
            k--;
        }

        // Remove leading zeros
        while (!ans.empty() && ans.front() == '0') {
            ans.pop_front();
        }

        // Convert list<char> to string
        string result(ans.begin(), ans.end());
        
        return result.empty() ? "0" : result;
    }
};

    
