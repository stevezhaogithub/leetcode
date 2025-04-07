//
//  main.c
//  05_142. 环形链表 II
//
//  Created by steve xiaohu zhao on 2025/4/7.
//

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    // 1. 特殊情况判断
    if (head == NULL || head->next == NULL) {
        // 表示链表无环，直接返回 NULL
        return NULL;
    }

    // 2. 定义快慢指针判断是否有环
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    // 遍历链表，判断是否有环
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            // 表示有环，此时让慢指针回到起始位置，然后快慢指针重新开始每次移动一步，向前移动
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            // 上述 while 循环遍历结束，表示: 找到了环的入口点
            return slow;
        }
    }
    return NULL;
}

int main(int argc, const char *argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
