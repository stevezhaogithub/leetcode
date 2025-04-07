/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
function ListNode(val) {
    this.val = val;
    this.next = null;
}

/**
 * @param {ListNode} head
 * @return {boolean}
 */
var hasCycle = function(head) {
    // 1. 判断特殊情况
    if (!head || !head.next) {
        return false;
    }

    // 2. 定义快慢指针
    let slow = head;
    let fast = head;

    // 3. 开始循环遍历
    while (fast && fast.next) {
        slow = slow.next;
        fast = fast.next.next;

        if (slow === fast) {
            return true;
        }
    }

    // 4. 循环完毕，如果 slow !== fast，则表示无环，返回 false
    return false;
};
