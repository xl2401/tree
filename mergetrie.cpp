#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

struct node{
  string key;
  unordered_map<string, node *> children;
  node(int x):key(x){};
};

void insert(node *&root, string key)
{
    node *pre = root;
    for (int i = 0; i < key.length(); i++)
    {
        if (pre->children.find(string(key[i])) != pre->children.end())
        {
            pre = pre->children[string(key[i])];
        }
        else
        {
            pre->children[string(key[i])] = new node(string(key[i]));
            pre = pre->children[string(key[i])];
        }
    }
}

node *initialize()
{
  node *root = new node("/0");
  return root;
}

node *merge(node *cur)
{
  string key = "";
  node *lastnode  = NULL;
  while(true)
  {
    key += cur->key;
    if(cur->children.size() == 0 || cur->children.size()>1 || cur->key == "\0")
    {
      lastnode  = cur;
      break;
    }
    cur = cur->children.begin()->second;
  }
  //every time  create a root
  node *root = new node(key);
  for(auto it = lastnode->children.begin(); it != lastnode->children.end(); it++)
  {
    node *subtrie = merge(it->second);
    root->children[subtrie->key] = subtrie;
  }
  return root;
}
