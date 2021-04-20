//
// Created by zcsh on 2021/4/19.
//
#include "stdio.h"
#include "math.h"
#include "memory.h"
#include "stdbool.h"
#include "limits.h"
#include "stdlib.h"

bool isSubsequence(char *s, char *t) {
    while (*s != '\0' && *t != '\0') if (*s == *t++) s++;
    return *s == '\0';
}