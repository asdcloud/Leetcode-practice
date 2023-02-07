#include <stdio.h>
#include <stdlib.h>


int totalFruit(int* fruits, int fruitsSize){
    int max = 0;
    int counter = 1;
    int repeated = 1;
    int set[2];
    if (fruitsSize <= 2) {
        return fruitsSize;
    }
    set[0] = fruits[0];
    set[1] = -1;
    for (int a = 1; a < fruitsSize; a++) {
        if (fruits[a] == set[0] || fruits[a] == set[1]) {
            if (fruits[a] == fruits[a - 1]) {
                repeated++;
            }else {
                repeated = 1;
            }
            counter++;
        }else if (fruits[a] != set[0] && set[1] == -1) {
            set[1] = fruits[a];
            repeated = 1;
            counter++;
        }else if (fruits[a] != set[0] && fruits[a] != set[1]) {
            if (counter > max) {
                max = counter;
            }
            counter = repeated + 1;
            repeated = 1;
            set[0] = fruits[a - 1];
            set[1] = fruits[a];
        }
        if (a == fruitsSize - 1) {
            if (counter > max) {
                max = counter;
            }
        }
    }
    return max;
}
int main() {
    int fruit[9] = {1,0,1,4,1,4,1,2,3};
    int size = 9;
    printf("%d", totalFruit(&fruit, size));
}