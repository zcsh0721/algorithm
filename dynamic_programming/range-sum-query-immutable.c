//
// Created by zcsh on 2021/4/19.
//
#include "stdio.h"
#include "math.h"
#include "memory.h"
#include "stdbool.h"
#include "limits.h"
#include "stdlib.h"

typedef struct {
    int *numsSum;
} NumArray;


NumArray *numArrayCreate(int *nums, int numsSize) {
    NumArray *na = malloc(sizeof(NumArray));
    na->numsSum = malloc(sizeof(int) * numsSize + 1);
    na->numsSum = 0;
    for (int i = 1; i < numsSize; ++i) {
        na->numsSum[i] = *(nums + i) + na->numsSum[i - 1];
    }
    return na;
}

int numArraySumRange(NumArray *obj, int left, int right) {
    return obj->numsSum[right] - obj->numsSum[left];
}

void numArrayFree(NumArray *obj) {
    free(obj->numsSum);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);

 * numArrayFree(obj);
*/