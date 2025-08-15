class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        vector<string>words;
        int i=0;
        while(i<n){
            while(i<n && s[i]== ' ') i++;
            int j = i;
            string ans = "";
            while(j<n && s[j] != ' '){
                ans +=s[j];
                j++;
            }
            if(!ans.empty())words.push_back(ans);
            i=j;
        }

        reverse(words.begin(),words.end());

        string res = "";
        for(auto it:words){
            res+=it;
            res+=" ";
        }
        if (!res.empty() && res.back() == ' ') {
    res.pop_back(); // remove trailing space
}
        return res;
    }
};