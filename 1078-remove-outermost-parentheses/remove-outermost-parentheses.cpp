class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int opened = 0;  // current depth

        for (char c : s) {
            if (c == '(') {
                if (opened > 0) res += c; // keep if not the outermost
                opened++;
            } else { // c == ')'
                opened--;
                if (opened > 0) res += c; // keep if not the outermost
            }
        }
        return res;
    }
};
