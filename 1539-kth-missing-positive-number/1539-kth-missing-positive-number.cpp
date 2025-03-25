class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int num=1, idx=0, missct=0;
        while(!arr.empty()){
            if(idx<arr.size()&& arr[idx]==num)idx++;
            else{
                missct++;
                if(missct==k)return num;
            }
            num++;

        }
        return -1;
    }
};