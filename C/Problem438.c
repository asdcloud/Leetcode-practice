#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* findAnagrams(char * s, char * p, int* returnSize){
    int ascii[256];
    int ascaa[256];
    int* result;
    int counter = 0;
    result = malloc(1 * sizeof(int));
    if (strlen(p) > strlen(s)) {
        *returnSize = 0;
        return NULL;
    }
    for (int a = 0; a < 256; a++) {
        ascii[a] = 0;
        ascaa[a] = 0;
    }

    for (int a = 0; a < strlen(p); a++) {
        ascaa[p[a]]++;
    }
    for (int a = 0; a < strlen(s); a++) {
        int judge = 1;
        for (int b = 0; b < 256; b++) {
            ascii[b] = 0;
        }
        for (int b = a; b < (a + strlen(p)); b++) {
            if (ascaa[s[b]] == 0) {
                judge = 0;
                a = b;
                break;
            }
            ascii[s[b]]++;
            if (ascaa[s[b]] < ascii[s[b]]) {
                judge = 0;
                while(s[a] != s[b]) {
                    a++;
                }
                break;
            }
        }
        if (judge == 1) {
            counter++;
            result = realloc(result, counter * sizeof(int));
            result[counter - 1] = a;
        }
    }
    *returnSize = counter;
    return result;
}

int main() {
    char a[99] = "cbaebabacd";
    char b[99] = "abc";
    int re;
    int* ans = findAnagrams(&a, &b, &re);
    printf("%d\n", re);
    for (int c = 0; c < re; c++) {
        printf("%d ", ans[c]);
    }
}