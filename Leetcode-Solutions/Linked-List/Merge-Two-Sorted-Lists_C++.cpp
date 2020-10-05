/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
static auto x = []() {ios_base::sync_with_stdio(false); cin.tie(NULL); return NULL; }();
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      ListNode* temp = NULL, *headl3 = NULL;      
      if((not l2 && l1) || (l1 && l2 && l1->val < l2->val)){
          headl3 = new ListNode(l1->val);
          temp = headl3;
          l1 = l1->next;
      }
      else if((not l1 && l2) || (l1 && l2 && l1->val >= l2->val)){
          headl3 = new ListNode(l2->val);
          temp = headl3;
          l2 = l2->next;
      }
      
      while(l1 && l2){
          if(l1->val < l2->val){
              temp->next = new ListNode(l1->val);
              temp = temp->next;
              l1 = l1->next;
          }
          else{
              temp->next = new ListNode(l2->val);
              temp = temp->next;
              l2 = l2->next;
          }
      }
      while(l1){
          temp->next = new ListNode(l1->val);
          temp = temp->next;
          l1 = l1->next;
      }          
      while(l2){
          temp->next = new ListNode(l2->val);
          temp = temp->next;
          l2 = l2->next;
      } 
      return headl3;
    }
};