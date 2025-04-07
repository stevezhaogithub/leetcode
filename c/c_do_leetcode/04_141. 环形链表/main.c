//
//  main.c
//  04_141. 环形链表
//
//  Created by steve xiaohu zhao on 2025/4/7.
//

#include <stdbool.h>
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
bool hasCycle(struct ListNode *head) {
    // 1. 如果链表为空或只有一个结点，无环
    if (head == NULL || head->next == NULL) {
        return false;
    }

    // 2. 定义快慢指针
    struct ListNode *fast = head;
    struct ListNode *slow = head;

    // 3.
    // 开始循环遍历，直到快指针到达末尾或者快慢指针相遇（如果有环，则永远不会到达末尾）
    while (fast != NULL && fast->next != NULL) {
        // 慢指针每次移动 1 步
        slow = slow->next;
        // 快指针每次移动 2 步
        fast = fast->next->next;
        // 判断快慢指针是否相遇
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

int main(int argc, const char *argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
