#include<bits/stdc++.h>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
    void dfs(Node* node,Node* cp,vector<Node*>&visited)
    {
        visited[cp->val]=cp;
        for(auto ele:node->neighbors)
        {
            if(visited[ele->val]==NULL)
            {
                Node *newNode= new Node(ele->val);
                (cp->neighbors).push_back(newNode);
                dfs(ele,newNode,visited);
            }
            else
            {
                (cp->neighbors).push_back(visited[ele->val]);
            }
        }
    }
    
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)
        {
            return NULL;
        }
        vector<Node*> visited(1000,NULL);
        Node* cp= new Node(node->val);
        dfs(node,cp,visited);
        return cp;
    }
};