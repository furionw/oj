#include <map>

using namespace std;

struct RandomListNode 
{
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};


struct Label
{
	Label(int label, RandomListNode* next) : label(label), next(next) {}
	friend bool operator< (const Label& a, const Label& b)
	{
		return a.label < b.label;
	}
	int label;
	RandomListNode* next;
};

class Solution
{
public:
	RandomListNode *copyRandomList(RandomListNode *head)
	{
		if (head == NULL)
		{
			return NULL;
		}
		auto node = nodes[Label(head->label, head->next)];
		if (node == NULL)
		{
			node = new RandomListNode(head->label);
			nodes[Label(head->label, head->next)] = node;
		}
		node->next = copyRandomList(head->next);
		node->random = copyRandomList(head->random);
		return node;
	}

private:
	map<Label, RandomListNode*> nodes;
};

int main()
{

	return 0;
}