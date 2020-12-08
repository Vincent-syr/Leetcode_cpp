#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;


/*
 * @Author: Vincent-syr
 * @Date: 2020-12-07 15:52:18
 * @LastEditTime: 2020-12-07 16:50:56
 * @Description: file content

https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/
剑指 Offer 40. 最小的k个数  EASY
输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。


示例 1：

输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]
示例 2：

输入：arr = [0,1,2,1], k = 1
输出：[0]
 
限制：

0 <= k <= arr.length <= 10000
0 <= arr[i] <= 10000

 */


    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(k > arr.size() || arr.size()==0)  return  arr; 
        if(k == 0)  return {};

        // 降序队列，大顶堆；
        priority_queue <int,vector<int>, less<int>> q;
        for(int i=0; i<arr.size(); i++){
            // 前k个元素建堆
            if(i<k){
                q.push(arr[i]);
            }
            else{
                if(arr[i] < q.top()){
                    q.pop();
                    q.push(arr[i]);
                }
            }
        }
        vector<int> res;
        while(k-- > 0){
            res.push_back(q.top());
            q.pop();
        }
        return res;
    }

