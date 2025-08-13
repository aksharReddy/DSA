class Solution {
public:
    int characterReplacement(string s, int k) {
    //     int replacements =0;
    //     int maxf=0;
    //     int maxlen = 0;
    //     int changes=0;

    //    for(int i = 0;i<s.size();i++){
    //         int hash[256]={0};
    //         for(int j=i;j<s.size();j++){
    //             hash[s[j]-'A']++;
    //             maxf = max(maxf,hash[s[j]-'A']);
    //             replacements = (j-i+1) - maxf;
    //             if(replacements<=k){
    //                 maxlen = max(maxlen,j-i+1);
    //             }
    //             else{
    //                 break;
    //             }
    //         }
    //    }
    //    return maxlen;
    // }
     int l = 0, maxf = 0, maxlen = 0;
        unordered_map<char, int> freq;

        for (int r = 0; r < s.size(); r++) {
            freq[s[r]]++;
            maxf = max(maxf, freq[s[r]]); // update max frequency in current window

            // while replacements needed exceed k, shrink from left
            while ((r - l + 1) - maxf > k) {
                freq[s[l]]--;
                l++;
            }

            maxlen = max(maxlen, r - l + 1);
        }

        return maxlen;
    }
};
