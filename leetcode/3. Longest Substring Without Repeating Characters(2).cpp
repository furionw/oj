class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		int length = 0;
		string subs;
		for (char c: s) {
			if (subs.find(c) == string::npos) {
				subs += c;
				length = max(length, int(subs.size()));
			} else
				subs = subs.substr(subs.find(c)+1) + c;
		}
		return length;
	}
};