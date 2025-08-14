class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int l = 0, r = 0;
        unordered_map<char,int> mpp;
        int count = 0;

        while (r < n) {
            // Expand the window by including s[r]
            mpp[s[r]]++;

            // When we have all 3 chars
            while (mpp.size() == 3) {
                // All substrings from current (l, r) to (l, n-1) are valid
                count += (n - r);

                // Shrink from left
                mpp[s[l]]--;
                if (mpp[s[l]] == 0) {
                    mpp.erase(s[l]);
                }
                l++;
            }
            r++;
        }
        return count;
    }
};
