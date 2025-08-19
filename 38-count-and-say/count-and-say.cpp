class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";

        string prev = "1";
        for (int i = 2; i <= n; i++) {
            string curr = "";
            int cnt = 1;
            for (int j = 1; j <= prev.size(); j++) {
                if (j < prev.size() && prev[j] == prev[j - 1]) {
                    cnt++;
                } else {
                    curr += to_string(cnt) + prev[j - 1];
                    cnt = 1;
                }
            }
            prev = curr;
        }
        return prev;
    }
};
