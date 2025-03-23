class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        if (n == 0) return 0; 
      vector<int>prefixmax(n), suffixmax(n);
         prefixmax[0]= height[0];
        for(int i=1; i<height.size(); i++){
            prefixmax[i]= max(prefixmax[i-1], height[i]);
        }
        suffixmax[n-1]=height[n-1];
        for(int i=n-2; i>=0; i--){
            suffixmax[i]= max(suffixmax[i+1], height[i]);
        }
        int totquantity=0;
        for(int i=0; i<height.size(); i++){
           int  watertrapped= min(prefixmax[i], suffixmax[i])- height[i];
                  if(watertrapped >0)totquantity+=watertrapped;
        }
        return totquantity;
    }
};