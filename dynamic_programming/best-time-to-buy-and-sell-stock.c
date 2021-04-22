#include "stdio.h"
#include "math.h"
#include "memory.h"
#include "stdbool.h"
#include "limits.h"
#include "stdlib.h"

int maxProfit(int *prices, int pricesSize) {

    int min = *prices;
    int result = 0;
    for (int i = 1; i < pricesSize; ++i) {
        if (*(prices + i) > min) {
            result = fmax(result, *(prices + i) - min);
        }
        min = fmin(*(prices + i), min);
    }

    return result;
}
