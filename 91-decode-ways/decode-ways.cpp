class Solution {

    int f(int i,string&s,vector<int>&dp){
        int n = s.size();
        if(s[i] == '0') return 0;
        if(i == n) return 1;
        if(dp[i]!=-1) return dp[i];
        //check condition 10<=s[i]s[i+1]<=25 check for 0s if not possbile return 0
        int takeone = f(i+1,s,dp);
        int taketwo=0;
        if(i<n-1){
            int num = (s[i]-'0')*10 + s[i+1]-'0';
            if(num>=10 && num<=26){
                 taketwo = f(i+2,s,dp);
            }
        }
        return dp[i]=takeone + taketwo;

    }
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n+1,-1);
        return f(0,s,dp);
    }
};