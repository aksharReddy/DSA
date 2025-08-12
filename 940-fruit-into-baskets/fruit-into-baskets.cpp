class Solution {
public:
    int totalFruit(vector<int>& a) {
        int l=0;
        int r=0;
        int n = a.size();
        int maxlen = 0;
        map<int,int>mpp;
        for(int r=0;r<n;r++){
            mpp[a[r]]++;

            if(mpp.size()>2){
                mpp[a[l]]--;
                if(mpp[a[l]] == 0) mpp.erase(a[l]);
                l++;
                
            }
            if(mpp.size()<=2){
                maxlen = max(maxlen,r-l+1);
            }
        }
        return maxlen;

    }
};