class Solution {
public:
     vector<int> findnse(vector<int>& nums){
    stack<int>st;
    int n=nums.size();
    vector<int>sol(n,n);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && nums[i]<=nums[st.top()]){
            st.pop();
        }
        if(!st.empty()){
            sol[i]=st.top();
        }
        st.push(i);
    }
    return sol;
     }
    vector<int> findpsee(vector<int>& nums){
    stack<int>st;
    int n=nums.size();
    vector<int>sol(n,-1);
    for(int i=0;i<n;i++){
        while(!st.empty() && nums[i]<nums[st.top()]){
            st.pop();
        }
        if(!st.empty()){
            sol[i]=st.top();
        }
        st.push(i);
    }
    return sol;
     }


 vector<int> findpge(vector<int>& nums){
    stack<int>st;
    int n=nums.size();
    vector<int>sol(n,-1);
    for(int i=0;i<n;i++){
        while(!st.empty() && nums[i]>nums[st.top()]){
            st.pop();
        }
        if(!st.empty()){
            sol[i]=st.top();
        }
        st.push(i);
    }
    return sol;
     }
  vector<int> findngee(vector<int>& nums){
    stack<int>st;
    int n=nums.size();
    vector<int>sol(n,n);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && nums[i]>=nums[st.top()]){
            st.pop();
        }
        if(!st.empty()){
            sol[i]=st.top();
        }
        st.push(i);
    }
    return sol;
     }


    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long sum1=0,sum2=0,total=0;
       
        vector<int> nse=findnse(nums);
         vector<int> psee=findpsee(nums);
          vector<int> nge=findngee(nums);
         vector<int> pgee=findpge(nums);

        for(int i=0;i<n;i++){
            long long sleft=i-psee[i];
            long long sright=nse[i]-i;
            long long gleft=i-pgee[i];
            long long gright=nge[i]-i;
            sum1=(sum1+sleft*sright*nums[i]);
            sum2=(sum2+gleft*gright*nums[i]);
        }
        
         total = (sum2 - sum1 );
        return total;
    }
};