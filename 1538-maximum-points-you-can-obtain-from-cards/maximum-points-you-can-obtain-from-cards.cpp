class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int n = a.size();
        int lsum = 0;
        int rsum = 0;
        
        for(int i=0;i<k;i++) lsum+=a[i];
        int maxi = lsum;
        for(int i =0;i<k;i++){
            lsum=lsum-a[k-i-1];
            rsum = rsum+a[n-i-1];
            maxi = max(maxi,lsum+rsum);
        }
        return maxi;
    }
};