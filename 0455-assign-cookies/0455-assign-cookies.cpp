class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
     int a=g.size();
     int b = s.size();
     int l=0,r=0;
     sort(g.begin(),g.end());
     sort(s.begin(), s.end());
     while(l<a && r<b){
        if(g[l]<=s[r]){
            l++;
        }
        r++;

     }
     return l;
    }
};