class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // set<int> st;
        // for (auto i : nums) {
        //     st.insert(i);
        // }

        // // Optional: If you want to overwrite nums with unique value
        //  int idx = 0;
        // for (int val : st) {
        //     nums[idx++] = val;
        // }

        // return st.size();  // Number of unique elements
        if(nums.empty()) return 0;
        
        int i = 0;
        for(int j = 1; j < nums.size(); j++) {
            if(nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};