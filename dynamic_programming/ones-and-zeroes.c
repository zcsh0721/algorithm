//
// Created by zcsh on 2021/4/19.
//
#include "stdio.h"
#include "math.h"
#include "memory.h"
#include "stdbool.h"
#include "limits.h"
#include "stdlib.h"

int findMaxForm(char **strs, int strsSize, int m, int n) {

    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < strsSize && strs[i] != NULL; ++i) {
        int count[] = {0, 0};
        char *str = strs[i];
        if (str == NULL) break;
        while (*str != '\0') {
            count[*(str++) - '0']++;
        }

        for (int k = m; k >= count[0]; --k) {
            for (int j = n; j >= count[1]; --j) {
                dp[k][j] = fmax(dp[k - count[0]][j - count[1]] + 1, dp[k][j]);
            }
        }
    }

    return dp[m][n];
}
