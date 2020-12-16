#include <iostream>
#include <vector>
using namespace std;
/*
 * @Author: Vincent-syr
 * @Date: 2020-12-16 14:48:12
 * @LastEditTime: 2020-12-16 15:01:15
 * @Description: file content
https://leetcode-cn.com/problems/maximum-subarray/
53. 最大子序和  easy
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶:

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

解答：
    仍然可以使用dp状态转移来做，dp[i]即以i结尾的最大子串的sum；
    但由于dp[i]仅与dp[i-1]和nums[i]有关，所以空间上可以只保留prev和cur；
复杂度分析：
    时间O(N)
    空间O(1)
 */


    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0)    return 0;

        int maxSum = INT_MIN;
        int prev = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            int cur = prev>0? prev+nums[i]: nums[i];
            maxSum = max(cur, maxSum);
            // update
            prev = cur;
        }

        return maxSum;

    }