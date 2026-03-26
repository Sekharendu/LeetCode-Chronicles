class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
       int rows = mat.size(), cols = mat[0].size();

        long long totalSum = 0;
        unordered_map<long long,int> lowerMap, upperMap, leftSideMap, rightSideMap;

        for (auto &r : mat) {
            for (int val : r) {
                totalSum += val;
                lowerMap[val]++;
                rightSideMap[val]++;
            }
        }

        long long topSum = 0;

        // Horizontal cuts
        for (int r = 0; r < rows - 1; r++) {
            for (int c = 0; c < cols; c++) {
                int value = mat[r][c];
                topSum += value;

                upperMap[value]++;
                lowerMap[value]--;
            }

            long long bottomSum = totalSum - topSum;

            if (topSum == bottomSum) return true;

            long long difference = abs(topSum - bottomSum);

            if (topSum > bottomSum) {
                if (check(upperMap, mat, 0, r, 0, cols-1, difference)) return true;
            } else {
                if (check(lowerMap, mat, r+1, rows-1, 0, cols-1, difference)) return true;
            }
        }

        long long leftSum = 0;
        for (int c = 0; c < cols - 1; c++) {
            for (int r = 0; r < rows; r++) {
                int value = mat[r][c];
                leftSum += value;

                leftSideMap[value]++;
                rightSideMap[value]--;
            }

            long long rightSum = totalSum - leftSum;
            if (leftSum == rightSum) return true;

            long long difference = abs(leftSum - rightSum);

            if (leftSum > rightSum) {
                if (check(leftSideMap, mat, 0, rows-1, 0, c, difference)) return true;
            } else {
                if (check(rightSideMap, mat, 0, rows-1, c+1, cols-1, difference)) return true;
            }
        }

        return false;
    }

    bool check(unordered_map<long long,int>& freqMap, vector<vector<int>>& mat,
           int rStart, int rEnd, int cStart, int cEnd, long long diff) {

        int numRows = rEnd - rStart + 1;
        int numCols = cEnd - cStart + 1;

        // single cell
        if (numRows * numCols == 1) return false;

        // 1D row
        if (numRows == 1) {
            return (mat[rStart][cStart] == diff || mat[rStart][cEnd] == diff);
        }

        // 1D column
        if (numCols == 1) {
            return (mat[rStart][cStart] == diff || mat[rEnd][cStart] == diff);
        }

        return freqMap[diff] > 0;
    }
};
