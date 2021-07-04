#include "Tree.h"

#include <queue>


std::string Tree::serialize(TreeNode* root)
{
    if (nullptr==root)
    {
        return std::string("[]");
    }
    std::queue<TreeNode*> layer;
    layer.push(root);
    std::string ret("[");
    bool firstChar = true;
    do 
    {
        TreeNode* temp = layer.front();
        layer.pop();
        if (firstChar)
        {
            firstChar = false;
        }
        else
        {
            ret.append(",");
        }
        
        if (nullptr != temp)
        {
            ret.append(std::to_string(temp->val));
            layer.push(temp->left);
            layer.push(temp->right);
        }
        else
        {
            ret.append("null");
        }

    } while (!layer.empty());
    while (ret.size()>=5 && ret.substr(ret.size()-4, ret.size())=="null")
    {
        ret.erase(ret.size() - 5, 5);
    }
    ret.append("]");
    return ret;
}

Tree::TreeNode* Tree::deserialize(std::string data)
{
    if (data.empty() || data == "[]")
    {
        return nullptr;
    }
    std::queue<TreeNode*> layer;
    int index = 1;
    std::string rootStr = findSubStringByChar(data, 1, data.size() - 1, index, ',');
    TreeNode* root = new TreeNode(std::stoi(rootStr, 0));
    layer.push(root);
    do 
    {
        TreeNode* temp = layer.front();
        layer.pop();
        if (nullptr!= temp)
        {
            std::string leftStr = findSubStringByChar(data, 1, data.size() - 1, index, ',');
            TreeNode* left = nullptr;
            if (leftStr!="null" && !leftStr.empty())
            {
                left = new TreeNode(std::stoi(leftStr, 0));
                layer.push(left);
            }
            temp->left = left;
           
            std::string rightStr = findSubStringByChar(data, 1, data.size() - 1, index, ',');
            TreeNode* right = nullptr;
            if (rightStr != "null" && !rightStr.empty())
            {
                right = new TreeNode(std::stoi(rightStr, 0));
                layer.push(right);
            }
            temp->right = right;
        }
    } while (!layer.empty());
    return root;
}

std::string Tree::findSubStringByChar(std::string s, int beginIndex, int endIndex, int& subStrBeginIndex, char endChar)
{
    std::string ret;
    int i = subStrBeginIndex;
    while (i<= endIndex)
    {
        if (s[i]==endChar || i == endIndex)
        {
            ret = s.substr(subStrBeginIndex, i - subStrBeginIndex);
            subStrBeginIndex = i + 1;
            break;
        }
        i++;
    }
    return ret;
}
