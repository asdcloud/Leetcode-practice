#include <stdio.h>
#include <stdlib.h>

int jump(int* nums, int numsSize){
    int max = 0;
    int maxindex = 0;
    int result = 0;

    if (numsSize == 1) {
        return 0;
    }
    for (int a = 0; a < numsSize; a++) {
        if (a + nums[a] >= numsSize - 1) {
            result++;
            break;
        }
        for (int b = a; b <= a + nums[a]; b++) {
            if (nums[b] == 0) {
                continue;
            }
            if (b + nums[b] >= max) {
                max = b + nums[b];
                maxindex = b;
            }
        }
        a = maxindex - 1;
        result++;
    }
    return result;
}


int main() {
    int nums[3] = {1,2,3};
    int size = 3;
    printf("%d\n", jump(&nums, size));
}