#include <iostream>
#include "Node.h"
using namespace std;


/* 
剑指 Offer 35. 复杂链表的复制
https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof/
请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。

示例 1：
输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]

示例 2：
输入：head = [[1,1],[2,1]]
输出：[[1,1],[2,1]]

示例 3：

输入：head = [[3,null],[3,0],[3,null]]
输出：[[3,null],[3,0],[3,null]]

示例 4：
输入：head = []
输出：[]
解释：给定的链表为空（空指针），因此返回 null。
 

提示：

-10000 <= Node.val <= 10000
Node.random 为空（null）或指向链表中的节点。
节点数目不超过 1000 。


解答：
方法一：构建<原节点 :新节点>的hashmap

方法二：拼接 + 拆分
考虑构建 原节点 1 -> 新节点 1 -> 原节点 2 -> 新节点 2 -> …… 的拼接链表，如此便可在访问原节点的 random 指向节点的同时找到新对应新节点的 random 指向节点。

算法流程：
复制各节点，构建拼接链表:

设原链表为 node1 \rightarrow node2 \rightarrow \cdotsnode1→node2→⋯ ，构建的拼接链表如下所示：
node1 \rightarrow node1_{new} \rightarrow node2 \rightarrow node2_{new} \rightarrow \cdots
node1→node1 
new
​	
 →node2→node2 
new
​	
 →⋯

构建新链表各节点的 random 指向：

当访问原节点 cur 的随机指向节点 cur.random 时，对应新节点 cur.next 的随机指向节点为 cur.random.next 。
拆分原 / 新链表：

设置 pre / cur 分别指向原 / 新链表头节点，遍历执行 pre.next = pre.next.next 和 cur.next = cur.next.next 将两链表拆分开。
返回新链表的头节点 res 即可。

复杂度分析：
时间复杂度 O(N)O(N) ： 三轮遍历链表，使用 O(N)O(N) 时间。
空间复杂度 O(1)O(1) ： 节点引用变量使用常数大小的额外空间。

作者：jyd
链接：https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof/solution/jian-zhi-offer-35-fu-za-lian-biao-de-fu-zhi-ha-xi-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */

    Node* copyRandomList(Node* head) {
        if(head == nullptr) return head;

        // 1.构建raw node1 -> new node1 --> raw node2 .... --> new node n
        auto cur = head;

        while(cur != nullptr){
            auto node = new Node(cur->val);
            node->next = cur->next;
            cur->next = node;
            cur = cur->next->next;
        }
        // 2.构建各节点指向新的new
        cur = head;
        while(cur != nullptr){
            if(cur->random != nullptr){
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        // 3. 拆分两链表, 不改变输入
        auto pre = head;
        cur = head->next;
        auto newHead = head->next;
        while(cur->next != nullptr){
            pre->next = pre->next->next;
            cur->next = cur->next->next;
            pre = pre->next;
            cur = cur->next;
        }
        pre->next = nullptr;
        return newHead;
    }



