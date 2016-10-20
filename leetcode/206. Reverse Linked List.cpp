#include <algorithm>
#include <iostream>

using namespace std;

struct ListNode
{
	ListNode(int _v, ListNode* _n) :
			val(_v), next(_n)
	{
	}
	int val;
	ListNode* next;
};

class Solution
{
public:
	ListNode* reverseList(ListNode* head)
	{
		// return iteratively(head);
		return recursively(nullptr, head);
	}

private:
	ListNode* iteratively(ListNode *head)
	{
		auto cur = head;
		for (ListNode* pre = nullptr; cur != nullptr;)
		{
			if (cur->next == nullptr)
			{
				cur->next = pre;
				return cur;
			} else
			{
				swap(pre, cur->next);
				swap(pre, cur);
			}
		}
		return nullptr;
	}

	// note that this tail recursive algo should be transformed into iterate algo to obtain the better performance
	ListNode* recursively(ListNode *pre, ListNode *cur)
	{
		if (cur == nullptr)
		{
			return pre;
		} else
		{
			swap(pre, cur->next);
			return recursively(cur, pre);
		}
	}
};
