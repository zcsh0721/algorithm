#include "stdio.h"
#include "math.h"
#include "memory.h"
#include "stdbool.h"
#include "limits.h"
#include "stdlib.h"

int minimumTotal(int **triangle, int triangleSize, int *triangleColSize) {
    int dp[triangleSize];
    memset(dp, 0, sizeof(dp));
    dp[0] = triangle[0][0];
    int result = INT_MAX;

    for (int i = 1; i < triangleSize; ++i) {
        dp[i] = dp[i - 1] + triangle[i][i];
        for (int j = i - 1; j > 0; --j) {
            dp[j] = fmin(dp[j], dp[j - 1]) + triangle[i][j];
        }
        dp[0] += triangle[i][0];
    }

    for (int i = 0; i < triangleSize; ++i) result = fmin(dp[i], result);

    return result;
}

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    int f[triangleSize];
    memset(f, 0, sizeof(f));
    f[0] = triangle[0][0];
    for (int i = 1; i < triangleSize; ++i) {
        f[i] = f[i - 1] + triangle[i][i];
        for (int j = i - 1; j > 0; --j) {
            f[j] = fmin(f[j - 1], f[j]) + triangle[i][j];
        }
        f[0] += triangle[i][0];
    }
    int ret = f[0];
    for (int i = 1; i < triangleSize; i++) ret = fmin(ret, f[i]);
    return ret;
}

int main()
{
    int triangle[4][4] = {
            {2},
            {3, 4},
            {6, 5, 7},
            {4, 1, 8, 3}
    };

    triangle[4] = {2};
    int *triangleColSize = 4;


    int result = minimumTotal(&triangle, 4, &triangleColSize);
    return 0;
}