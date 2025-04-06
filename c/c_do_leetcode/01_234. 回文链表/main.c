//
//  main.c
//  01_234. 回文链表
//
//  Created by steve xiaohu zhao on 2025/4/6.
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
bool isPalindrome(struct ListNode *head) {
    // 基本思路: 找到链表中点，反转后半部分链表，比较前后两部分链表
    // 时间复杂度 O(n)，空间复杂度 O(1)

    // 1. 判断链表是否为空或者只有1个结点
    if (head == NULL || head->next == NULL) {
        return true;
    }

    // 2. 通过快慢指针找到链表的中点
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    struct ListNode *prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next; // 快指针移动两步
        prev = slow;             // 记录慢指针的前一个结点
        slow = slow->next;       // 慢指针移动一步
    }

    // 断开前半部分和后半部分
    prev->next = NULL;

    // 3. 反转后半部分链表
    struct ListNode *curr = slow; // 当前结点
    struct ListNode *next = NULL; // 下一个结点
    prev = NULL;                  // 前一个结点

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // 4. 比较前后两部分链表是否相同
    struct ListNode *p1 = head; // 前半部分指针
    struct ListNode *p2 = prev; // 后半部分指针（反转后的头部）

    while (p1 != NULL && p2 != NULL) {
        if (p1->val != p2->val) { // 不是回文
            return false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    return true;
}

int main(int argc, const char *argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
