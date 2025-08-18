class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string>ans ; 

        int last_group  = -1;

        for(int i=0;i<words.size();i++){
            if(groups[i]!=last_group){
                ans.push_back(words[i]);
                last_group = groups[i];
            }
        }
        return ans;
    }
};