/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void addlinked (struct ListNode** head, struct ListNode** last, int r) {
    struct ListNode* new = NULL;
    new = (struct ListNode*)malloc(sizeof(struct ListNode));
    new->next = NULL;
    new->val = r;
    if (*head == NULL) {
        *head = new;
        *last = new;
    }else {
        (*last)->next = new;
        *last = new;
    }
    return; 
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* head = NULL;
    struct ListNode* last = NULL;
    struct ListNode* temp = NULL;
    int sum = 0;
    int counter = 0;
    while(l1 && l2) {
        sum = sum + l1->val + l2->val;
        counter = sum / 10;
        sum = sum % 10;
        addlinked(&head, &last, sum);

        sum = counter;
        l1 = l1->next;
        l2 = l2->next;
    }
    temp = (l1 == NULL ? l2 : l1);
    while(temp) {
        sum = sum + temp->val;
        counter = sum / 10;
        sum = sum % 10;
        addlinked(&head, &last, sum);

        sum = counter;
        temp = temp->next;
    }
    if (sum) {
        addlinked(&head, &last, sum);
    }
    return head;
}