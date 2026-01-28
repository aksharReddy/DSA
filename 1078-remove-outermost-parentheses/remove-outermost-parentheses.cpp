class Solution {
public:
    string removeOuterParentheses(string s) {
        int opened = 0;
        string ans = "";

        for(int i=0;i<s.length();i++){
            char ch = s[i];
            if(ch == '('){
                if(opened>0)ans+=ch;
                opened++;
            }
            else{
                opened --;
                if(opened>0)ans+=ch;
            }
        }
        return ans;
    }
};