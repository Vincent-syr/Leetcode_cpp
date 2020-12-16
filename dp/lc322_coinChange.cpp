#include <iostream>
#include <vector>
#include "../array/arrayUtil.h"
using namespace std;

/*
 * @Author: Vincent-syr
 * @Date: 2020-12-12 13:41:42
 * @LastEditTime: 2020-12-12 14:16:29
 * @Description: file content
https://leetcode-cn.com/problems/coin-change/
322. 零钱兑换   middle
给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

你可以认为每种硬币的数量是无限的。

 

示例 1：

输入：coins = [1, 2, 5], amount = 11
输出：3 
解释：11 = 5 + 5 + 1
示例 2：

输入：coins = [2], amount = 3
输出：-1
示例 3：

输入：coins = [1], amount = 0
输出：0
示例 4：

输入：coins = [1], amount = 1
输出：1
示例 5：

输入：coins = [1], amount = 2
输出：2
 

提示：

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104


解法：      耗时30分钟
    动态规划，dp[i]代表amount为i时，需要多少硬币；
    也可以调用回溯框架；用memo数组保存状态；
复杂度分析：
    时间：O(n*k)，n代表amount的值，k代表coins数量；
    空间: O(n), dp数组；
ref:
    https://github.com/labuladong/fucking-algorithm/blob/master/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%E7%B3%BB%E5%88%97/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%E8%AF%A6%E8%A7%A3%E8%BF%9B%E9%98%B6.md

 */



    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        if(amount < 0)  return -1;
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for(int i=1; i<=amount; i++){
            for(int val: coins){
                if(i - val >= 0 && dp[i-val] != INT_MAX){
                    dp[i] = min(dp[i], dp[i-val] +1);
                }
            }
        }
        printVec(dp);
        return dp[amount]==INT_MAX? -1: dp[amount];
    }

    int main(int argc, char const *argv[])
    {
        vector<int> coins = {1,2,5};
        int amount = 11;
        cout<< coinChange(coins, amount);
        return 0;
    }
    