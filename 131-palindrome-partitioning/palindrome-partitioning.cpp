class Solution {
public:
    vector<vector<int>> memo; // -1 = not calculated, 0 = false, 1 = true

bool palindrome(string &s,int start,int end){
    if (memo[start][end] != -1) 
        return memo[start][end]; // return stored result

    int i = start, j = end;
    while(i <= j){
        if(s[i] != s[j]) 
            return memo[start][end] = 0; // false
        i++;
        j--;
    }
    return memo[start][end] = 1; // true
}


    void f(int index,string &s,vector<vector<string>>&res,vector<string>&path){

            if(index == s.size()){
                res.push_back(path);
                return;
            }
        
        for(int i=index;i<s.size();i++){
            if(palindrome(s,index,i)){
                path.push_back(s.substr(index,i-index+1));
                f(i+1,s,res,path);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        int n = s.size();
memo.assign(n, vector<int>(n, -1));
        vector<string>path;
        f(0,s,res,path);
        return res;
    }
};