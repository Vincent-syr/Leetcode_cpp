#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

/*
 * @Author: Vincent-syr
 * @Date: 2020-12-03 21:11:03
 * @LastEditTime: 2020-12-03 21:30:29
 * @Description: file content
 * 
https://leetcode-cn.com/problems/next-greater-element-ii/
503. 下一个更大元素 II      middle
给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。数字 x 的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1。

示例 1:

输入: [1,2,1]
输出: [2,-1,2]
解释: 第一个 1 的下一个更大的数是 2；
数字 2 找不到下一个更大的数； 
第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
注意: 输入数组的长度不会超过 10000。

解法：  耗时20分钟；

debug点：
   1）因为数组double了，所以while中的循环判定条件要由nums[i] > stk.top()， 改为nums[i] >= stk.top()；
   2）数组索引越界，stk.push(nums[i%nums.size()])，记住要由余数；
 */


   vector<int> nextGreaterElements(vector<int>& nums) {
      vector<int> res(nums.size());
      stack<int> stk;
      // 把数组循环拉长一倍；循环的那部分进栈
      for(int i=nums.size()*2-1; i>=0; i--){
         if(i >= nums.size()) stk.push(nums[i%nums.size()]);
         
         else{
            while(!stk.empty() && nums[i] >= stk.top()){
               stk.pop();
            }
            res[i] = stk.empty()? -1: stk.top();
            stk.push(nums[i]);
         }
      }
      return res;
   }


   int main(int argc, char const *argv[])
   {
      vector<int> nums = {1,4,3,2};
      nextGreaterElements(nums);

      return 0;
   }
   