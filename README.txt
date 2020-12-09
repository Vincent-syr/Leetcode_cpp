## 1. stack
    单调栈：
    「单调栈」monotonic stack，解决了一类问题「Next Greater Number]
        lc496 下一个更大元素 I
        lc503 搭配循环数组；
        lc739 同lc496几乎一样，res中的结果由value改成了索引的距离
        lc581 单调栈变种, 常规是得到下一个更大元素，此处是得到最后一个更大元素；

    重点题：
        lc581 findUnsortedSubarray，
            子数组和排序问题，可以使用单调栈空间O(N)；
            也可以不用单调栈，仅仅用O(1)的空间复杂度解决；

## 2. ListNode
经典题目：
    反转链表
        lc206: naive版本 
            https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/solution/fan-zhuan-lian-biao-yi-dong-de-shuang-zhi-zhen-jia/
            naive双指针法   空间O(1)
            递归法： 空间O(n)
            栈：空间O(n)，和递归法本质一样；
        lc25:   hard
            按照group反转指针，每个group有k个元素；
            双指针法，注意每次loop后链表指针发生的变化，细节；

        lc92_reverseBetween： middle
            给定区间lo，hi，在这个区间内反转指针
            同样可以用双指针法解决，注意每个指针的next指向什么；

    lc23_mergeKLists: 合并k个有序链表
        方法1：分治策略，先两两合并，再进一步两两合并；类似归并排序；
        方法2：使用优先队列，每次从k个list中选择value最小的；
            自定义priority_queue的比较方法

## 3. tree
    完全二叉树性质：
        lc222_countLevel.cpp
    判断两颗树是否相同：
        lc572_isSubtree：中的函数isSameTree

    二叉搜索树BST：
        框架即前序遍历：
            void BST(TreeNode root, int target) {
                if (root.val == target)
                    // 找到目标，做点什么
                if (root.val < target) 
                    BST(root.right, target);
                if (root.val > target)
                    BST(root.left, target);
            }
        题目：
            lc450_deleteNode(*有debug), lc701_insertIntoBST, 
            lc99_recoverTree(回复BST，hard)


## 4. Array
    lc189 旋转数组，空间=O（1）的方法很巧妙；


## window_slide
    1) 双指针
    2） 正经滑动窗口
        单调队列：与单调栈相比唯一的区别，多了一个front()成员函数，即队列可以去首元素；


## dp
    最长递增子序列类型：
        lc673_findNumberOfLIS: 最长递增自序列的个数；
        lc300_lengthOfLIS：最长递增子序列的长度；

