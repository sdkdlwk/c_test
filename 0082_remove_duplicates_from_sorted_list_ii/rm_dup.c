#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head)
{
    struct ListNode dummy;
    struct ListNode *p, *q, *prev;
    prev = &dummy;
    dummy.next = head;
    p = q = head;
    while (p != NULL) {
        while (q != NULL && q->val == p->val) {
            q = q->next;
        }
        if (p->next == q) {
            prev = p;
        } else {
            prev->next = q;
        }
        p = q;
    }
    return dummy.next;
}

int main(int argc, char **argv)
{
    int i;
    struct ListNode *head = NULL;
    struct ListNode *prev = NULL;
    struct ListNode *p;
    for (i = 0; i < argc - 1; i++) {
        p = malloc(sizeof(*p));
        p->val = atoi(argv[i + 1]);
        p->next = NULL;
        if (head == NULL) {
            head = p;
            prev = head;
        } else {
            prev->next = p;
            prev = p;
        }
    }
    p = deleteDuplicates(head);
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
    return 0;
}
