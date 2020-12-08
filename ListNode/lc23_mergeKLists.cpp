#include <iostream>
#include <queue>
#include "ListNode.h"
using namespace std;

/*
 * @Author: Vincent-syr
 * @Date: 2020-12-07 22:18:58
 * @LastEditTime: 2020-12-08 10:17:21
 * @Description: file content
https://leetcode-cn.com/problems/merge-k-sorted-lists/
23. 合并K个升序链表  hard
给你一个链表数组，每个链表都已经按升序排列。

请你将所有链表合并到一个升序链表中，返回合并后的链表。

 

示例 1：

输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]
解释：链表数组如下：
[
  1->4->5,
  1->3->4,
  2->6
]
将它们合并到一个有序链表中得到。
1->1->2->3->4->4->5->6
示例 2：

输入：lists = []
输出：[]
示例 3：

输入：lists = [[]]
输出：[]
 
方法一：逐一合并两条链表, 
思路
    k个list，1个ans，每次取一个和ans合并，即调用merge2List的API；
复杂度分析：
    时间：O(K^2*N)；第一次合并ans长度为n，第二次2*n，第k次k*n；第i次合并时间复杂度O(in)；
    空间：O(1)

方法二：分治合并
思路：
    考虑优化方法一，用分治的方法进行合并。将 k 个链表配对并将同一对中的链表合并；
    第一轮合并以后， k个链表被合并成了 k/2个链表，平均长度为2n/k;  k/4个链表。k/8个链表；
    重复这一过程，直到我们得到了最终的有序链表。
复杂度分析：
    时间：O(kn*logk)
    空间：O(logK)


方法三：使用优先队列从k个list中每次最小的节点；
思路
    这个方法和前两种方法的思路有所不同，我们需要维护当前每个链表没有被合并的元素的最前面一个，k 个链表
    就最多有 k 个满足这样条件的元素，每次在这些元素里面选取 val 属性最小的元素合并到答案中。
    在选取最小元素的时候，我们可以用优先队列来优化这个过程。
复杂度分析：
    时间：O(kn*logk)；queue中有k个节点，每次插入和删除O(logk)，最多有kn个节点，所以O(kn*logk)；
    空间：O(K)。队列存储k个list的头结点，选取最小值pop；

 */
struct cmp{
    bool operator() (ListNode* a, ListNode* b){
        return (a->val > b->val);
    }
};

    // 采用优先队列的方法：
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        ListNode* dumb = new ListNode(0);
        auto cur = dumb;
        // k个头node 进入 q；
        for(ListNode* node: lists){
            if(node)    q.push(node);
        }
        while(! q.empty()){
            auto node = q.top();    q.pop();
            cur->next = new ListNode(node->val);
            cur = cur->next;
            if(node->next)   q.push(node->next);

        }
        // 每次选取最小的进入res，q.pop(), 新的进入
        return dumb->next;
    }



    int main(int argc, char const *argv[])
    {
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for(int i=0; i<10; i++){
            q.push(new ListNode(20 - i));
        }

        while(!q.empty()){
            cout<< q.top()->val << " ";
            q.pop();
        }
        return 0;
    }
    