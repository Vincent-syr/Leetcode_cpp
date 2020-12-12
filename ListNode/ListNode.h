/*
 * @Author: Vincent-syr
 * @Date: 2020-11-19 16:45:31
 * @LastEditTime: 2020-12-11 17:47:54
 * @Description: file content
 */
#include <iostream>
#include <vector>

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    
};


ListNode* createList(std::vector<int> &nums){
  ListNode* head = new ListNode(0);   // dumb node
  auto cur = head;
  for(int num: nums){
    cur->next = new ListNode(num);
    cur = cur->next;
  }
  return head->next;
}


void outputList(ListNode* head){
  auto cur = head;
  while(cur){
    std::cout<< cur->val;
    if(cur->next)   std::cout<<" -> ";
    cur = cur->next;
  }
  std::cout<<std::endl;
}



