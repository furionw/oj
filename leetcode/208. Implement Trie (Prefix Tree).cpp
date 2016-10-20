struct TrieNode
{
	map<char, shared_ptr<TrieNode>> children;
	bool is_word = false;
};

class Trie
{
public:
	Trie(): root(shared_ptr<TrieNode>(new TrieNode)) {}

	// Inserts a word into the trie.
	void insert(string word) const
	{
		if (word.empty())
		{
			return ;
		}
		auto node = root;
		for (size_t i = 0; i < word.size(); node = node->children[word[i ++]])
		{
			if (node->children.find((word[i])) == node->children.end())
			{
				node->children[word[i]] = shared_ptr<TrieNode>(new TrieNode);
			}
		}
		node->is_word = true;
	}

	// Returns if the word is in the trie.
	bool search(string word) const
	{
		auto node = searchNode(word);
		return node!=nullptr && node->is_word;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) const
	{
		return searchNode(prefix) != nullptr;
	}

private:
	shared_ptr<TrieNode> searchNode(string word) const
	{
		auto node = root;
		for (size_t i = 0; i < word.size(); node = node->children[word[i ++]])
		{
			if (node->children.find(word[i]) == node->children.end())
			{
				return nullptr;
			}
		}
		return node;
	}

	shared_ptr<TrieNode> root;
};