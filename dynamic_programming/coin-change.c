//
// Created by zcsh on 2021/4/19.
//
#include "stdio.h"
#include "math.h"
#include "memory.h"
#include "stdbool.h"
#include "limits.h"
#include "stdlib.h"

int coinChange(int *coins, int coinsSize, int amount) {
    if (amount == 0) return 0;
    int dp[amount + 1];
    for (int i = 0; i < amount + 1; ++i)
        dp[i] = amount + 1;

    for (int i = 0; i < coinsSize; ++i) {
        if (coins[i] > amount) continue;
        dp[coins[i]] = 1;
        for (int j = coins[i] + 1; j < amount + 1; ++j) {
            dp[j] = fmin(dp[j - coins[i]] + 1, dp[j]);
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

int main() {
    int value[] = {3, 7, 405, 436};
    printf("%d\n", coinChange(value, 4, 8839));
    return 0;
}