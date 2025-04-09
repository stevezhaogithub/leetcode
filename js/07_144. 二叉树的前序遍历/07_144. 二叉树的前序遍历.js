
function TreeNode(val, left, right) {
    this.val = (val === undefined) ? 0 : val;
    this.left = (left === undefined) ? null : left;
    this.right = (right === undefined) ? null : right;
}

/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var preorderTraversal = function(root) {
    // 初始化结果数组
    const result = [];

    // 定义递归辅助函数
    function preorder(node) {
        if (!node) {
            return;
        }
        result.push(node.val);
        preorder(node.left);
        preorder(node.right);
    }

    // 调用递归函数
    preorder(root);
    return result;
};
