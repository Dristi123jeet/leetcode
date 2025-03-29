class Solution {
public:
int countp(vector<int>&a, int maxSum){
    int summ=0; int partitions=1;
    long long subarraySum = 0;
     int n = a.size(); 
    for (int i = 0; i < n; i++) {
        if (subarraySum + a[i] <= maxSum) {
            //insert element to current subarray
            subarraySum += a[i];
        }
        else {
            //insert element to next subarray
            partitions++;
            subarraySum = a[i];
        }
    }
    return partitions;
}


    int splitArray(vector<int>& a, int k) {
       int low = *max_element(a.begin(), a.end());
    int high = accumulate(a.begin(), a.end(), 0);

    // for (int maxSum = low; maxSum <= high; maxSum++) {
    //     if (countp(a, maxSum) == k)
    //         return maxSum;
    // }
    // return -1;
    // }
    while (low <= high) {
        int mid = (low + high) / 2;
        int partition = countp(a, mid);
        if (partition > k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}
};