#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

class Node{
    public:
        int val;
        Node* left;
        Node* right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};


Node* input_tree()
{
    int val; cin >> val;
    Node* root;
    queue<Node*> q;
    
    if(val == -1)
        root = NULL;
    else
        root = new Node(val);

    if(root != NULL)
        q.push(root);

    
    while(!q.empty())
    {
        Node* p = q.front();
        q.pop();


        Node* myLeft, *myRight;
        int l, r; cin >> l >> r;
        
        if(l == -1)
            myLeft = NULL;
        else
            myLeft = new Node(l);

        if(r == -1)
            myRight = NULL;
        else
            myRight = new Node(r);

        p->left = myLeft;
        p->right = myRight;


        if(p->left)
            q.push(p->left);

        if(p->right)
            q.push(p->right);

    }
    return root;
}

int cout_leaf_nodes(Node* root)
{
    if(root == NULL)
        return 0;
    
    if(root->left == NULL && root->right == NULL)
        return 1;

    int l = cout_leaf_nodes(root->left);
    int r = cout_leaf_nodes(root->right);

    return l+r;
}

int main()
{

    Node* root = input_tree();
    cout << cout_leaf_nodes(root) << endl;
    
    

    return 0;
}