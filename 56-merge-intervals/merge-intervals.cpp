class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // Step 1: Sort by start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i) {
            // Get last interval in merged
            vector<int>& last = merged.back();

            // Check for overlap
            if (intervals[i][0] <= last[1]) {
                // Merge intervals
                last[1] = max(last[1], intervals[i][1]);
            } else {
                // No overlap
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};