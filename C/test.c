#include <stdio.h>

struct node {
    int val;
    struct node *next;
};

int main() {
    struct node a;
    struct node b;
    a.next = &b;
    a.val = 999;
    printf("%d", a.next);
}