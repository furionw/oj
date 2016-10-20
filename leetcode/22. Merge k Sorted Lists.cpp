#include <vector>
#include <queue>

using namespace std;

struct ListNode
{
	ListNode* next;
	int val;
	ListNode(int x): val(x), next(NULL) {}
};

class Solution 
{
public:
	struct cmp
	{
		bool operator () (const ListNode* a, const ListNode* b)
		{
			return a->val > b->val;
		}
	};
	ListNode *mergeKLists(vector<ListNode *> &lists) 
	{
		ListNode *head=NULL, *cur=NULL;
		priority_queue<ListNode*, vector<ListNode*>, cmp> ss;

		for (auto it = lists.begin(); it != lists.end(); ++ it)
		{
			if (*it != NULL)
			{
				ss.push(*it);
			}
		}
		while(ss.empty() == false)
		{
			auto top = ss.top();
			if (head == NULL)
			{
				head = cur = top;
			} else
			{
				cur->next = top;
				cur = cur->next;
			}
			ss.pop();
			if (top->next != NULL)
			{
				ss.push(top->next);
			}
		}

		return head;
	}
};

struct ListNode
{
    ListNode* next;
    int val;
    ListNode(int x): val(x), next(NULL) {}
};

struct cmp
{
    bool operator () (const ListNode* a, const ListNode* b)
    {
        return a->val > b->val;
    }
};

int main()
{
    priority_queue<ListNode*, vector<ListNode*>, cmp> q;

    return 0;
}