class Solution {
public:
   
        int findDays(vector<int> &weights, int cap) {
    int days = 1; //First day.
    int load = 0;
    int n = weights.size(); //size of array.
    for (int i = 0; i < n; i++) {
        if (load + weights[i] > cap) {
            days += 1; //move to next day
            load = weights[i]; //load the weight.
        }
        else {
            //load the weight on the same day.
            load += weights[i];
        }
    }
    return days;
}

 int shipWithinDays(vector<int>& weights, int d) {
    //Find the maximum and the summation:
    int maxi = *max_element(weights.begin(), weights.end());
    int sum = accumulate(weights.begin(), weights.end(), 0);

    int l=maxi;
    int h=sum;
    while(l<=h){
   int m= (l+h)/2;
   int days=findDays(weights,m);
   if(days<=d)h= m-1;
   else l=m+1;
    }
   return l;

    //dummy return statement:
    
    }
};