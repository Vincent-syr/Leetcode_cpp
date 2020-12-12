#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


/*
 * @Author: Vincent-syr
 * @Date: 2020-12-11 18:14:04
 * @LastEditTime: 2020-12-11 18:23:08
 * @Description: file content
https://leetcode-cn.com/problems/contains-duplicate-ii/
219. 存在重复元素 II    easy
给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的 绝对值 至多为 k。

 

示例 1:

输入: nums = [1,2,3,1], k = 3
输出: true
示例 2:

输入: nums = [1,0,1,1], k = 1
输出: true
示例 3:

输入: nums = [1,2,3,1,2,3], k = 2
输出: false



解法：
    hashmap， key为num，val为出现的索引，再次出现时即对索引作差，判断是否<=k;
 */



    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(int i=0; i<nums.size(); i++){
            int num = nums[i];
            if(map.count(num) != 0){
                int idx = map[num];
                if(i - idx <= k)     return true;
            }
            map[num] = i;
        }
        return false;
    }