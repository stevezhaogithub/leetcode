//
//  main.c
//  03_50. Pow(x, n)
//
//  Created by steve xiaohu zhao on 2025/4/6.
//

#include <stdio.h>
//
// double myPow(double x, int n) {
//
//    // 1. 特殊情况判断
//    if (x == 1)
//        return 1;
//    if (n == 0)
//        return 1;
//    if (n == 1)
//        return x;
//    long long N = n;
//
//    if (N < 0) {
//        x = 1 / x;
//        N = -N;
//    }
//
//    // 2. 开始计算
//    // 声明一个用于存储结果的变量
//    double result = 1;
//    // 声明一个用于存储当前乘积的变量
//    double curr_product = x;
//    // 开始计算乘积
//    while (N > 0) {
//        if (N % 2 == 1) {
//            // N 是奇数, 累乘结果
//            result *= curr_product;
//        }
//        // N 不是奇数, 计算 curr_product 的平方。相当于 curr_product
//        // 变量的值只计算一次
//        curr_product *= curr_product;
//        N /= 2;
//    }
//    return result;
//}

// 递归实现
// 1. 定义一个递归函数
double powHelper(double x, long long n) {
    // 1. 递归退出条件
    if (n == 0) {
        return 1.0; // 返回 1.0 直接就是 double 类型，省去了类型转换
    }
    // 2. 递归计算 x^(n/2)
    double half = powHelper(x, n / 2);
    return (n % 2 == 0) ? half * half : half * half * x;
}

double myPow(double x, int n) {
    long long N = n;
    if (N < 0) {
        x = 1.0 / x; // x = 1.0 / x; 比 x = 1 / x; 少了一次隐式类型转换
        N = -N;
    }
    return powHelper(x, N);
}
int main(int argc, const char *argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
