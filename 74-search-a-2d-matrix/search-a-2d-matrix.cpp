class Solution {
public:
     bool binarySearch(vector<int>& row, int target) {
        int low = 0, high = row.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (row[mid] == target) return true;
            else if (row[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }

    // Main search function
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; i++) {
            // Check if target could be in this row
            if (matrix[i][0] <= target && target <= matrix[i][n - 1]) {
                if (binarySearch(matrix[i], target)) return true;
            }
        }

        return false;
    }
};