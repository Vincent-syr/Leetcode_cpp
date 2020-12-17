#include <iostream>
#include <vector>
using namespace std;
/*
 * @Author: Vincent-syr
 * @Date: 2020-12-12 17:05:36
 * @LastEditTime: 2020-12-12 17:12:14
 * @Description: file content
https://leetcode-cn.com/problems/single-number/
136. 只出现一次的数字   middle
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:

输入: [2,2,1]
输出: 1
示例 2:

输入: [4,1,2,1,2]
输出: 4

解答：
    位运算: ^
    答案是使用位运算。对于这道题，可使用异或运算⊕。异或运算有以下三个性质。

    任何数和 00 做异或运算，结果仍然是原来的数，即a⊕0=a。
    任何数和其自身做异或运算，结果是 00，即a⊕a=0。
    异或运算满足交换律和结合律，即a⊕b⊕a=b⊕a⊕a=b⊕(a⊕a)=b⊕0=b

    记a1-am有重复数字，a0无重复数字。由于交换律和结合律，故可以写为:
    (a1^a1)^(a2^a2)^...^(am^am)^a0 = a0
 */




    int singleNumber(vector<int>& nums) {
        int res = nums[0];
        for(int i=1; i<nums.size(); i++){
           res = nums[i] ^ res; 
        }
        return res;
    }