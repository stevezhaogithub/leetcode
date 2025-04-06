//
//  main.c
//  02_704. 二分查找
//
//  Created by steve xiaohu zhao on 2025/4/6.
//

#include <stdio.h>

//// 通过遍历实现
// int search(int *nums, int numsSize, int target) {
//     int start = 0, end = numsSize - 1;
//     // 未优化整数溢出问题。如果 start 和 end 单独都不会使整数溢出，但是 start
//     +
//     // end 可能会导致整数溢出 int mid = (start + end) / 2;
//
//     // 优化，防止整数溢出
//     int mid = start + (end - start) / 2;
//     while (start <= end) {
//         if (target < nums[mid]) {
//             end = mid - 1;
//         } else if (target > nums[mid]) {
//             start = mid + 1;
//         } else {
//             return mid;
//         }
//         mid = start + (end - start) / 2;
//     }
//     return -1;
// }

// 辅助函数
int binarySearch(int *nums, int start, int end, int target) {
    // 递归终止条件
    if (start > end) {
        return -1;
    }

    int mid = start + (end - start) / 2;
    if (nums[mid] == target) {
        return mid;
    } else if (target < nums[mid]) {
        return binarySearch(nums, start, mid - 1, target);
    } else {
        return binarySearch(nums, mid + 1, end, target);
    }
}
// 通过递归实现
int search(int *nums, int numsSize, int target) {
    return binarySearch(nums, 0, numsSize - 1, target);
}

int main(int argc, const char *argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
