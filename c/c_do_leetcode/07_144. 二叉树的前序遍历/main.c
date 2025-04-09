//
//  main.c
//  07_144. 二叉树的前序遍历
//
//  Created by steve xiaohu zhao on 2025/4/9.
//

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 辅助递归函数
void preorder(struct TreeNode *node, int *result, int *returnSize) {
    if (!node) {
        return;
    }
    // 将当前结点值存入结果数组
    result[(*returnSize)++] = node->val;
    // 递归左子树
    preorder(node->left, result, returnSize);
    // 递归右子树
    preorder(node->right, result, returnSize);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *preorderTraversal(struct TreeNode *root, int *returnSize) {

    // 如果跟结点为空, 返回空数组, 同时设置 *returnSize 为 0.
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    // 初始化结果数组
    int capacity = 100;
    int *result = (int *)malloc(sizeof(int) * capacity);
    *returnSize = 0;

    // 调用递归函数
    preorder(root, result, returnSize);

    // 返回结果数组
    return result;
}

int main(int argc, const char *argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
