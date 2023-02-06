#include <stdio.h>
#include <stdlib.h>


int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    *returnSize = numsSize;
    int* result = malloc(numsSize * sizeof(int));
    for (int a = 0; a < n; a++) {
        result[a * 2] = nums[a];
        result[a * 2 + 1] = nums[a + n];

    }
    return result;
}


int main() {
    int nums[8] = {1,2,3,4,4,3,2,1};
    int n = 4;
    int size;
    for (int a = 0; a < 2 * n; a++) {
        printf("%d ", nums[a]);
    }
    printf("\n");
    int* ans = shuffle(&nums, 2 * n, n, &size);
    for (int a = 0; a < 2 * n; a++) {
        printf("%d ", ans[a]);
    }
    return 0;
}