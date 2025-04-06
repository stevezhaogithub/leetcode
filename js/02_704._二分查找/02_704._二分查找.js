/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    let start = 0, end = nums.length - 1;
    // 注意此处需要用 Math.floor() 将小数变成整数
    let mid = start + Math.floor((end - start) / 2);
    while (start <= end) {
        if (nums[mid] === target) {
            return mid;
        } else if (target < nums[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
        mid = start + Math.floor((end - start) / 2);
    }
    return -1;
};
