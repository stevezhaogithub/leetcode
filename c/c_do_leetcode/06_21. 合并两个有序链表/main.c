//
//  main.c
//  06_21. 合并两个有序链表
//
//  Created by steve xiaohu zhao on 2025/4/7.
//

#include <stdio.h>

// Definition for singly-linked list.
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
struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2) {
    // 1. 定义一个 dummy 结点和一个 current 指针
    // Create a dummy node as the starting point of the result list.
    struct ListNode dummy;
    struct ListNode *curr = &dummy;

    // 2. 循环遍历 list1 和 list2
    // While both lists are not empty, compare and merge
    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            curr->next = list1;
            list1 = list1->next;
        } else {
            curr->next = list2;
            list2 = list2->next;
        }
        curr = curr->next;
    }

    // 3. 处理剩余结点
    // Handle remaining nodes (if any)
    curr->next = (list1 != NULL) ? list1 : list2;

    // 4. 返回拼接好的新链表(dummy 结点本身并不包含数据，从 dummy.next
    // 才开始包含数据）
    // Handle the head of merged list (skip dummy node)
    return dummy.next;
}

int main(int argc, const char *argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
