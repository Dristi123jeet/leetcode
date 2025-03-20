class Solution {
public:
bool possible(vector<int> &arr, int day, int m, int k) {
    int n = arr.size(); //size of the array
    int cnt = 0;
    int noOfB = 0;
    // count the number of bouquets:
    for (int i = 0; i < n; i++) {
        if (arr[i] <= day) {
            cnt++;
        }
        else {
            noOfB += (cnt / k);
            cnt = 0;
        }
    }
    noOfB += (cnt / k);
    return noOfB >= m;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val=m*1ll*k*1ll;
        if(val>bloomDay.size())return -1;
        int mini = INT_MAX, maxi = INT_MIN;
        for(int i=0; i<bloomDay.size(); i++){
            mini = min(mini, bloomDay[i]);
        maxi = max(maxi, bloomDay[i]);
        }
         int low = mini, high = maxi;
    while (low <= high) {
        int ans=-1;
        int mid = (low + high) / 2;
        if (possible(bloomDay, mid, m, k)) {
           ans=mid;
            high = mid - 1;
            
        }
        else low = mid + 1;
    }
    return low;
}
    
};