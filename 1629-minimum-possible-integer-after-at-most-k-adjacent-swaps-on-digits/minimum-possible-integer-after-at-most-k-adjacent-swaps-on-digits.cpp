class Solution {
public:
    string minInteger(string s, int K) {
        int n = s.size();
    for (int i = 0; i < n && K > 0; i++) {
        // Look ahead up to K steps to find max digit
        int maxPos = i;
        for (int j = i + 1; j < n && j - i <= K; j++) {
            if (s[j] < s[maxPos]) {
                maxPos = j;
            }
        }

        // Move the max digit to position i using adjacent swaps
        for (int j = maxPos; j > i; j--) {
            swap(s[j], s[j - 1]);
        }

        // Reduce K by the number of swaps used
        K -= (maxPos - i);
    }
    return s;
    }
};