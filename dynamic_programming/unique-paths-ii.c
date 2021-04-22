#include "stdio.h"
#include "math.h"
#include "memory.h"
#include "stdbool.h"
#include "limits.h"
#include "stdlib.h"

int uniquePathsWithObstacles(int **obstacleGrid, int obstacleGridSize, int *obstacleGridColSize) {
    if (obstacleGrid[0][0]) return 0;
    int n = obstacleGridSize, m = obstacleGridColSize[0];
    int dp[m];
    memset(dp, 0 , sizeof(dp));
    for (int i = 0; i < m && !obstacleGrid[0][i]; ++i) dp[i] = 1;
    for (int i = 1; i < n; ++i) {
        if (obstacleGrid[i][0]) dp[0] = 0;
        for (int j = 1; j < m; ++j)
            dp[j] = obstacleGrid[i][j] == 1 ? 0: dp[j] + dp[j - 1];
    };

    return dp[m - 1];
}