#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
 	ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
    ListNode *insertionSortList(ListNode *head) 
    {
    	// 可以处理head==NULL的情况，因此不用特判。
   		for (auto i = head; i != NULL; i = i->next) 
   		{
   			for (auto j = head; j != i; j = j->next)
   			{
   				if (i->val < j->val)
   				{
   					int next_value = j->val;
   					j->val = i->val;
   					for (auto k = j->next; k != i; k = k->next)
   					{
   						int tmp = k->val;
   						k->val = next_value;
   						next_value = tmp;
   					}
   					i->val = next_value;
   					break;
   				}
   			}
   		}
   		return head;
    }
};

int main()
{


	return 0;
}