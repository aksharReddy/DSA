class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
        int n =a.size();
        int l=0;
        int r=0;
        int o=0;
        int maxlen = 0;

        for(int r=0;r<n;r++){
            if(a[r]==0) o++;
            if(o>k){
                if(a[l]==0)o--;
                l++;
            }
            if(o<=k)maxlen = max(maxlen,r-l+1);
            
        }
        return maxlen;
    }
};