#include "stdio.h"
#include "math.h"
#include "memory.h"
#include "stdbool.h"
#include "limits.h"
#include "stdlib.h"

int minPathSum(int **grid, int gridSize, int *gridColSize) {
    int m = *gridColSize, n = gridSize;
    int dp[m];
    memset(dp, 0, sizeof(dp));
    dp[0] = grid[0][0];
    for (int i = 1; i < m; ++i) dp[i] = grid[0][i] + dp[i - 1];

    for (int i = 1; i < n; ++i) {
        dp[0] += grid[i][0];
        for (int j = 1; j < m; ++j) {
            dp[j] = fmin(dp[j], dp[j - 1]) + grid[i][j];
        }
    }
    return dp[m - 1];
}