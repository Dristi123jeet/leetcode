class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0, r = 0, c = 0, sidx = -1, m = INT_MAX;
        vector<int> hash(256, 0);

        for (int i = 0; i < t.size(); i++) {
            hash[t[i]]++;
        }

        while (r < s.size()) {
            if (hash[s[r]] > 0) {
                c++;
            }
            hash[s[r]]--;

            while (c == t.size()) {
                if (r - l + 1 < m) {
                    m = r - l + 1;
                    sidx = l;
                }
                hash[s[l]]++;
                if (hash[s[l]] > 0) {
                    c--;
                }
                l++;
            }

            r++;
        }

        return sidx == -1 ? "" : s.substr(sidx, m);
    }
};
