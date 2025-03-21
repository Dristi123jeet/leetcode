class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int>st;
        vector<int>ans; 

        int n = nums2.size();

        for(int i =n-1; i>=0;i--){
            if(st.empty()){
                ans.push_back(-1);
            }
            else if(!st.empty() && st.top()>nums2[i]){
                ans.push_back(st.top());
            }
            else{
                while(!st.empty() && st.top()<=nums2[i]){
                    st.pop();

                }
                if(st.empty()){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(st.top());
                }
            }
            st.push(nums2[i]);
        }
        reverse(ans.begin(),ans.end());

        vector<int> aans;
        int m = nums1.size();


        for(int i =0; i<m; i++){
            
            for(int j=0; j<n; j++){
                if(nums1[i]==nums2[j]){
                    aans.push_back(ans[j]);
                }
            }
            
        } 

        return aans;
 
    }
};