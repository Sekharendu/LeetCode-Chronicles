class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int row = mat.size();
        int col = mat[0].size();
        k = k % col;  
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i % 2 == 0) {
                    // even row , left rotate
                    if (mat[i][j] != mat[i][(j + k) % n])
                        return false;
                } else {
                    // odd row , right rotate
                    if (mat[i][j] != mat[i][(j - k + n) % n])
                        return false;
                }
            }
        }

        return true;
    }
};