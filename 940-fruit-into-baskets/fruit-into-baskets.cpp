class Solution {
public:
    int totalFruit(vector<int>& a) {
        int l=0;
        int maxlen = 0;
        map<int,int>mpp;

        for(int r=0;r<a.size();r++){
            if(mpp.size()>2){
                mpp[a[l]]--;
                if(mpp[a[l]] ==0) mpp.erase(a[l]);
                l++;
            }
            mpp[a[r]]+=1;
            if(mpp.size()<=2){
                maxlen = max(maxlen,r-l+1);
            }
            


        }
        return maxlen;

    }
};