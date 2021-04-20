//
// Created by zcsh on 2021/4/19.
//
#include "stdio.h"
#include "math.h"
#include "memory.h"
#include "stdbool.h"
#include "limits.h"
#include "stdlib.h"

bool divisorGame(int n) {
    bool dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[1] = false;
    for (int i = 2; i < n + 1; ++i) {
        for (int j = i - 1; j > 0; --j) {
            if (i % j == 0 && !dp[i - j])
                dp[i] = true;
        }
    }
    // return N % 2 == 0;
    return dp[n];
}