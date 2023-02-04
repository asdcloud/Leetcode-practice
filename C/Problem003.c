#include <stdio.h>


int lengthOfLongestSubstring(char * s){
    int ascii[256];
    for (int a = 0; a < 256; a++) {
        ascii[a] = 0;
    }

    int max = 0;
    int len = 0;
    if (strlen(s) == 1) {
        return 1;
    }
    for (int a = 0; a < strlen(s); a++) {
        len = 0;
        for (int a = 0; a < 256; a++) {
            ascii[a] = 0;
        }
        for (int b = a; b < strlen(s); b++) {
            if (ascii[s[b]] == 0) {
                ascii[s[b]]++;
                len++;
            }else {
                break;
            }
        }
        if (len > max) {
            max = len;
        }
    }
    return max;
}


int main() {
    char test[8] = "jbpnbwwd";
    printf("%d\n", lengthOfLongestSubstring(test));
}