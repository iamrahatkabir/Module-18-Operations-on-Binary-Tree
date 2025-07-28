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

class Node
{
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

void level_order(Node* root)
{
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        //1. Queue theke Node ber kore ana & Kothao store kora;
        Node* f = q.front();
        q.pop();

        //2. Oi Node ta niye kaj kora jeta ber kore ana hoyeche;
        cout << f->val << " ";

        //3. Children push kora;
        if(f->left != NULL) //if(f->left)
            q.push(f->left);

        if(f->right != NULL) //if(f->right)
            q.push(f->right);

    }
}


int main()
{
    Node* root = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);
    Node* d = new Node(50);
    Node* e = new Node(60);

    root->left = a;
    root->right = b;
    a->left = c;
    b->left = d;
    b->right = e;

    level_order(root);
 

    return 0;
}