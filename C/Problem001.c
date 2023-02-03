/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* result = malloc(2 * sizeof(int));
    for (int a = 0; a < numsSize; a++) {
        for (int b = a + 1; b < numsSize; b++) {
            if (nums[a] + nums[b] == target) {
                result[0] = a;
                result[1] = b;
            }
        }
    }
    *returnSize = 2;
    return result;
}