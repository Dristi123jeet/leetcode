class Solution {
public:
    vector<int> nse(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        vector<int> nsee(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[i] <= heights[st.top()]) st.pop();
            nsee[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nsee;
    }

    vector<int> pse(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        vector<int> psee(n);
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && heights[i] <= heights[st.top()]) st.pop();
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psee;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> nsee = nse(heights);
        vector<int> psee = pse(heights);
        int maxi = 0;
        for (int i = 0; i < heights.size(); ++i) {
            int width = nsee[i] - psee[i] - 1;
            int area = heights[i] * width;
            maxi = max(maxi, area);
        }
        return maxi;
    }
};
