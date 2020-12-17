#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
 * @Author: Vincent-syr
 * @Date: 2020-12-17 20:44:51
 * @LastEditTime: 2020-12-17 21:49:31
 * @Description: file content
https://leetcode-cn.com/problems/partition-equal-subset-sum/
416. 分割等和子集   middle
给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

注意:

每个数组中的元素不会超过 100
数组的大小不会超过 200
示例 1:

输入: [1, 5, 11, 5]

输出: true

解释: 数组可以分割成 [1, 5, 5] 和 [11].
 

示例 2:

输入: [1, 2, 3, 5]

输出: false

解释: 数组不能分割成两个元素和相等的子集.


解答：
    ref：https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247485103&idx=1&sn=8a9752e18ed528e5c18d973dcd134260&chksm=9bd7f8a7aca071b14c736a30ef7b23b80914c676414b01f8269808ef28da48eb13e90a432fff&scene=21#wechat_redirect
    dp[i][j]: nums[..i]中的元素凑出j的结果，是true还是false；

 */


    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num: nums)    sum += num;
        if(sum % 2 != 0)    return false;
        sum = sum / 2;
        int n = nums.size();
        
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1, 0));
        for(int i=0; i<=n; i++){
            dp[i][0] = true;
        }
        // i 是前i个nums， j代表凑的整数是j；
        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
                int val = nums[i-1];
                // val 大于背包的容量；
                if(val > j)     dp[i][j] = dp[i-1][j];
                else{
                    // 若前i-1个可以凑出j，则新的也可以；或者前i-1个可以凑整j-val，新来的正好填满；
                    dp[i][j] = dp[i-1][j] | dp[i-1][j-val];
                }
            }
        }
        return dp[n][sum];
    }