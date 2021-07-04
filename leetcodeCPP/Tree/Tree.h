#pragma once

#include <string>
#include <vector>

class Tree
{
public:
	struct TreeNode 
	{
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};
	// Encodes a tree to a single string.
	std::string serialize(TreeNode* root);

	// Decodes your encoded data to tree.
	TreeNode* deserialize(std::string data);

	//split string
	std::string findSubStringByChar(std::string s, int beginIndex, int endIndex, int& subStrBeginIndex, char endChar);
};

