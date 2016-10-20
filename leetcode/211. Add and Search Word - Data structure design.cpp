class TrieNode
{
public:
	TrieNode(): is_word(false) {}

	void insert(const string& word)
	{
		if (!word.empty())
		{
			nodes[word.front()] =
				nodes[word.front()] != nullptr ?
					nodes[word.front()] : shared_ptr<TrieNode>(new TrieNode);
			nodes[word.front()]->insert(word.substr(1));
		} else
		{
			is_word = true;
		}
	}

	bool search(string word)
	{
		if (!word.empty())
		{
			if (word.front() == '.')
			{
				bool ret = false;
				for (auto it = nodes.begin(); it != nodes.end() && !ret; ++ it)
				{
					ret = ret || it->second->search(word.substr(1));
				}
				return ret;
			} else if (nodes.find(word.front()) != nodes.end())
			{
				return nodes[word.front()]->search(word.substr(1));
			} else
			{
				return false;
			}
		}
		return is_word;
	}

	map<char, shared_ptr<TrieNode>> nodes;
	bool is_word;
};


class WordDictionary 
{
public:
	WordDictionary(): root(shared_ptr<TrieNode>(new TrieNode())) {}

    void addWord(string word) 
    {
        root->insert(word);
    }

    bool search(string word) 
    {
        return root->search(word);
    }

private:
	shared_ptr<TrieNode> root;
};