#include <iostream>
#include <vector>
#include "arrayUtil.h"
using namespace std;


/*
 * @Author: Vincent-syr
 * @Date: 2020-12-09 23:17:27
 * @LastEditTime: 2020-12-09 23:48:43
 * @Description: file content
https://leetcode-cn.com/problems/rotate-array/
189. 旋转数组   middle
给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: [1,2,3,4,5,6,7] 和 k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]
示例 2:

输入: [-1,-100,3,99] 和 k = 2
输出: [3,99,-1,-100]
解释: 
向右旋转 1 步: [99,-1,-100,3]
向右旋转 2 步: [3,99,-1,-100]
 
解法： 
    假设 n=7 且 k=3 。
    原始数组                  : 1 2 3 4 5 6 7
    反转所有数字后             : 7 6 5 4 3 2 1
    反转前 k 个数字后          : 5 6 7 4 3 2 1
    反转后 n-k 个数字后        : 5 6 7 1 2 3 4 --> 结果
 
复杂度：
    时间O(N)
    空间O(1)

 */
    inline void swap(vector<int>& nums, int lo, int hi){
        int tmp = nums[lo];
        nums[lo] = nums[hi];
        nums[hi] = tmp;
    }

    void rotate(vector<int>& nums, int k) {

        int n = nums.size();
        k = k%n;
        if(nums.size() == 0 || k==0)    return;
        // 先全部反转
        int lo = 0, hi = n - 1;
        while(lo < hi){
            swap(nums, lo, hi);
            lo++;   hi--;

        }
        lo = 0, hi = k - 1;
        while(lo < hi){
            swap(nums, lo, hi);
            lo++;   hi--;
        }
        // 反转k+1 ~n
        lo = k, hi = n-1;
        while(lo < hi){
            swap(nums, lo, hi);
            lo++;   hi--;
        }
    }

    int main(int argc, char const *argv[])
    {
        vector<int> nums = {1,2,3,4,5,6,7};
        printVec(nums);
        rotate(nums, 3);
        printVec(nums);

        // 输出vector
        // for(int i=0; i<nums.size(); i++){
        //     cout<< nums[i] <<", ";
        // }
        // cout<<endl;
        return 0;
    }
    
    