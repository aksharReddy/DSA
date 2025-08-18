class Solution {
public:
    void f(int open,int close,string curr,vector<string>&ans){
        if(open == 0 && close == 0){
            ans.push_back(curr);
            return;
        }
        if(open>0) f(open-1,close,curr+'(',ans);
        if(close >0 && close>open) f(open,close-1,curr+')',ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string curr= "";
        f(n,n,curr,ans);
        return ans;
    }
};