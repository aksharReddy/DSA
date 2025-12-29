class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0;
        int r = 0;
        int total = 0;
        int n = s.length();
        map<char,int>mpp;
        while(r<n){
            mpp[s[r]]++;
            while(mpp.size() == 3){
                total+=n-r;
                mpp[s[l]] --;
                if(mpp[s[l]] == 0){
                    mpp.erase(s[l]);
                }
                l++;
            }
            r++;
        }
        return total;
    }
};