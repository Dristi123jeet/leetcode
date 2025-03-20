class Solution {
public:

  int maximum(vector<int>& piles){
    int n=   piles.size();
    int maxi= INT_MIN;
    
    for(int i=0; i<n;i++){
        maxi = max(maxi, piles[i]);
    }
    return maxi;
  }
   
  double toth(vector<int>& piles, int hourly){
     double  h=0;
    int n=   piles.size();
    for(int i=0;i<n;i++){
        h+=ceil(double(piles[i])/ hourly);
 }
 return h;
  }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high= maximum(piles);
        int ans=0;
        while(low<=high){
            int mid= (low+high)/2;
           double  req= toth(piles,mid);
            if(req<=h){
                ans=mid;
                high= mid-1;
            }
            else low= mid+1;
        }
      return ans;
    }
};