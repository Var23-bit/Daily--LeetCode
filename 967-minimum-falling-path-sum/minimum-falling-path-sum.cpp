class Solution {
public:
    vector<vector<int>> t;
    int n, m;

    int solve(int i, int j, vector<vector<int>>& matrix) {
        if (j < 0 || j >= m) return INT_MAX;
        if (i == 0) return matrix[0][j];
        if (t[i][j] != INT_MIN) return t[i][j];

        int u  = solve(i - 1, j, matrix);
        int rd = (j > 0)     ? solve(i - 1, j - 1, matrix) : INT_MAX;
        int ld = (j < m - 1) ? solve(i - 1, j + 1, matrix) : INT_MAX;

        return t[i][j] = matrix[i][j] + min(u, min(rd, ld));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        t.assign(n, vector<int>(m, INT_MIN));

        int minim = INT_MAX;
        for (int j = 0; j < m; j++) {
            minim = min(minim, solve(n - 1, j, matrix));
        }
        return minim;
    }
};