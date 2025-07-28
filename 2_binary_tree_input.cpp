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

    Node* root  ;
    if(val == -1)
    {
        root = NULL;
    }
    else
    {
        root = new Node(val);
    }

    queue<Node*> q;

    if(root != NULL)
        q.push(root);


    while(!q.empty())
    {
        // 1. Node er value ber kore ene store kora;
        Node* parent = q.front();
        q.pop();


        //2. Ber kore ana Node(Node* parent) niye kaj kora;
        int l, r;
        cin >> l >> r;
        Node* myLeft, *myRight;

        if(l == -1)
        {
            myLeft = NULL;
        }
        else{
            myLeft = new Node(l);
        }

        if(r == -1)
        {
            myRight = NULL;
        }
        else{
            myRight = new Node(r);
        }

        parent->left = myLeft;
        parent->right = myRight; 


        //3. Children push kora;
        if(parent->left)
            q.push(parent->left);

        if(parent->right)
            q.push(parent->right);
    }

    return root;
}


int level_order(Node* root)
{

    if(root == NULL)
    {
        cout << "No Tree" << endl;
        return 0;
    }


    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        Node* f = q.front();
        q.pop();

        cout << f->val << " ";

        if(f->left)
            q.push(f->left);

        if(f->right)
            q.push(f->right);
    }
}


int main()
{
    Node* root = input_tree();

    level_order(root);

    return 0;
}