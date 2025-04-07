
// Definition for singly-linked list.
function ListNode(val, next) {
    this.val = (val === undefined ? 0 : val);
    this.next = (next === undefined) ? null : next);
}

/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} list1
 * @param {ListNode} list2
 * @return {ListNode}
 */
var mergeTwoLists = function (list1, list2) {
    // 1. Create a dummy node as the starting point of the result of list
    let dummy = new ListNode(0);
    let curr = dummy;

    // 2. While both lists are not empty, compare and merge
    while (list1 && list2) {
        if (list1.val <= list2.val) {
            curr.next = list1;
            list1 = list1.next;
        } else {
            curr.next = list2;
            list2 = list2.next;
        }
        curr = curr.next;
    }

    // 3. Handle remaining nodes (if any)
    curr.next = (list1) ? list1 : list2;

    // 4. Return the head of merged list (skip dummy node)
    return dummy.next;
};

