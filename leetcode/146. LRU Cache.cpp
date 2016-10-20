#include <map>
#include <list>

using namespace std;

class LRUCache
{
public:
    LRUCache(int c): capacity(c) {}
    
    int get(int key) 
    {
    	if (content.count(key) != 0)
    	{
			LRU_update(key, content[key]->val); // is it necessary?
			return content[key]->val;
    	} else
    	{
    		return -1;
    	}
    }
    
    void set(int key, int value) 
    {
        if (content.count(key) != 0) // in map
        {
        	LRU_update(key, value);
        } else if ( content.size() < capacity )
        {
        	LRU_insert(key, value);
        } else
        {
        	LRU_replace(key, value);
        }
    }

private:
	class Cache_node
	{
	public:
		int key;
		int val;
		Cache_node(int k, int v): key(k), val(v) {}
	};

    void LRU_update(int key, int value)
    {
		node_list.splice(node_list.begin(), node_list, content[key]);
		node_list.front().val = value; // use for set
		content[key] = node_list.begin();
    }

    void LRU_insert(int key, int value)
    {
		node_list.push_front(Cache_node(key, value));    	
		content[key] = node_list.begin();
    }

    void LRU_replace(int key, int value)
    {
		content.erase( node_list.back().key );
    	node_list.pop_back();
    	LRU_insert(key, value);
    }

	int capacity;
	list<Cache_node> node_list;
	map<int, list<Cache_node>::iterator> content;
};