#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
 * @Author: Vincent-syr
 * @Date: 2020-12-11 17:50:54
 * @LastEditTime: 2020-12-11 18:13:37
 * @Description: file content
https://leetcode-cn.com/problems/contains-duplicate/
217. 存在重复元素   easy
给定一个整数数组，判断是否存在重复元素。

如果任意一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。

 

示例 1:

输入: [1,2,3,1]
输出: true
示例 2:

输入: [1,2,3,4]
输出: false
示例 3:

输入: [1,1,1,3,3,4,3,2,4,2]
输出: true



解法：
    哈希set来存储 num，每次检查set总是否存在num，若存在则返回true；

 */


    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for(int num: nums){
            if(set.count(num) != 0)     return true;
            set.insert(num);
        }
        return false;
    }


