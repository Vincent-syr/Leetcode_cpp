#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


/*
 * @Author: Vincent-syr
 * @Date: 2020-12-11 20:27:12
 * @LastEditTime: 2020-12-11 22:05:40
 * @Description: file content

https://leetcode-cn.com/problems/contains-duplicate-iii/
220. 存在重复元素 III   middle
在整数数组 nums 中，是否存在两个下标 i 和 j，使得 nums [i] 和 nums [j] 的差的绝对值小于等于 t ，且满足 i 和 j 的差的绝对值也小于等于 ķ 。

如果存在则返回 true，不存在返回 false。

 

示例 1:

输入: nums = [1,2,3,1], k = 3, t = 0
输出: true
示例 2:

输入: nums = [1,0,1,1], k = 1, t = 2
输出: true
示例 3:

输入: nums = [1,5,9,1,5,9], k = 2, t = 3
输出: false



解答：  耗时一个半小时，特别恶心的数debug太久！！！以后对这种数跳过；
    分桶方法，将0~t, t+1~2t+1 。。。分别放置桶中，每次只需比较该相邻的桶即可，即只需要比较idx，idx-1，idx+1即可； 
    map：即桶，key是getIdx，val是nums[i], 窗口map保持k的大小；

附：
    系统提交这道题对c++有bug，会出特别恶心的数，如INT_MAX。。，耽误了我很长时间；思路懂得即可‘

 */


    long long getIdx(long long x, long long t){
        if(x >= 0)   return x / t;
        else   return ((x+1)/t -1);
    }

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(k == 0 || t < 0)  return false;
        unordered_map<long long, long long> map;   // idx, value
        long long w = (long long)t + 1;
        for(int i=0; i<nums.size(); i++){
            long long idx = getIdx(nums[i], w);

            if(map.count(idx) == 1){
                return true;
            }
            else if(map.count(idx-1) == 1){
                if(nums[i] - map[idx-1] <= w-1)   return true;
            }
            else if(map.count(idx+1) == 1){
                if(map[idx+1] - nums[i] <= w-1)   return true;
            }
            
            map[idx] = nums[i];

            // delete 窗口k之前的元素
            if(i >= k){
                long long idx2 = getIdx(nums[i-k], w);
                map.erase(idx2);
            }
        }
        return false;
    }


    int main(int argc, char const *argv[])
    {
        // unordered_map<int, int> map;
        // int val = map.count(4);
        // cout<<val;
        vector<int> nums = {1,2,5,6,7,2,4};
        int k = 1, t = 3;
        cout<< containsNearbyAlmostDuplicate(nums, k, t)<<endl;
        int i = 2147483647;
        double b = double(i)+1;
        cout<<b;
        return 0;
    }
    