/*
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
*/

class Solution {
public:
    Node* cloneGraph(Node* node) 
    {
        map<Node*, Node*>mpp; 
        queue<Node*>q; 

        if(node == NULL) return node;

        Node* clone = new Node(node->val);
        mpp[node] = clone;
        q.push(node);

        while(!q.empty())
        {
            Node* u = q.front();
            q.pop();

            for(auto &v : u->neighbors)
            {
                if(mpp.find(v) == mpp.end())
                {
                    Node* cloneNode = new Node(v->val);
                    mpp[v] = cloneNode;
                    q.push(v);
                }

                mpp[u]->neighbors.push_back(mpp[v]);
            }
        }

        return mpp[node];

    }
};