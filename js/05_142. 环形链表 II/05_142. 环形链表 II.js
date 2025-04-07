function ListNode(val) {
    this.val = val;
    this.next = null;
}
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var detectCycle = function(head) {
    // 1. 特殊情况判断
    if (!head || !head.next) {
        return null;
    }

    // 2. 定义快慢指针循环遍历
    let slow = head;
    let fast = head;

    // 循环遍历链表，确定是否有环
    while (fast && fast.next) {
        slow = slow.next;
        fast = fast.next.next;
        if (slow === fast) {
            // 找到环了, 重新设置慢指针起点，开始找环的入口
            slow = head;
            while (slow !== fast) {
                slow = slow.next;
                fast = fast.next;
            }
            // 返回环的入口点
            return slow;
        }
    }
    return null;
};
