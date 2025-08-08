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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* node1 , ListNode* node2){
        if(!node1) return node2;
        if(!node2) return node1;

        if(node1->val < node2->val){
            node1->next = mergeTwoLists(node1->next,node2);
            return node1;
        }
        else{
            node2->next = mergeTwoLists(node1,node2->next);
            return node2;
        }
    }
    ListNode* merge(vector<ListNode*>& lists,int s,int e){

        while(s<=e){
            int mid = s + (e-s)/2;
            if(s==e) return lists[s];
            else{
                ListNode* l1 = merge(lists,s,mid);
                ListNode* l2 = merge(lists,mid+1,e);
                return mergeTwoLists(l1,l2);
            }
        }
        return NULL;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists,0,lists.size()-1);
    }
};