class Solution {
public:

    void solve(string &digits,int index,vector<string>&map,string&current,vector<string>&ans){
        if(digits.size() == 0) return;
        if(index == digits.size()){
            ans.push_back(current);
            return;
        }
        string letters = map[digits[index]-'0'];    

        for(int i=0;i<letters.size();i++){
            current.push_back(letters[i]);
            solve(digits,index+1,map,current,ans);
            current.pop_back();

        }
    }
    vector<string> letterCombinations(string digits) {
      vector<string> map = {
    "",     // 0
    "",     // 1
    "abc",  // 2
    "def",  // 3
    "ghi",  // 4
    "jkl",  // 5
    "mno",  // 6
    "pqrs", // 7
    "tuv",  // 8
    "wxyz"  // 9
};
    // string current="";
    // vector<string>ans;
    // solve(digits,0,map,current,ans);
    // return ans;
     vector<string> ans;
     if(digits.size()==0) return {};
        ans.push_back("");  // start with empty string

        // iterate over each digit
        for (char digit : digits) {
            string letters = map[digit - '0'];
            vector<string> temp;

            // append all letters of current digit to existing combinations
            for (string &comb : ans) {
                for (char c : letters) {
                    temp.push_back(comb + c);
                }
            }

            ans = temp;  // update ans
        }

        return ans;
    }
};