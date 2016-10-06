/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
//second time
class Solution {
    unordered_map<int, UndirectedGraphNode*> myMap;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(myMap.find(node->label) != myMap.end()) {
            return node;
        }
        
        UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label);
        int _size = node->neighbors.size();
        new_node->neighbors.resize(_size);
        myMap[new_node->label] = new_node;
        
        for(int i = 0; i < _size; i++) {
            new_node->neighbors[i] = cloneGraph(node->neighbors[i]);
        }
        return new_node;
    }
};
//second time
 /**Create a new node if the node map doesn't already contain a node with this label, 
  * otherwise return the pointer to the node with that label from the node map. 
  * Add the children to new nodes recursively through BFS.
  **/
/*class Solution {
    unordered_map<int, UndirectedGraphNode*> track;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL) {return NULL;}
        if(track.find(node->label) != track.end()) {
            return track[node->label];
        }
        
        UndirectedGraphNode* new_node = new UndirectedGraphNode(node->label);
        new_node->neighbors.resize(node->neighbors.size());//resize is better than keep push_back
        track[new_node->label] = new_node;
        
        for(int i = 0; i < new_node->neighbors.size(); i++) {
            new_node->neighbors[i] = cloneGraph(node->neighbors[i]);
        }
        
        return new_node;
    }
};

/*class Solution {
private: unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> myMap;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node){return node;}//base case
        if(myMap.find(node) == myMap.end()){//node is not in myMap
            myMap[node] = new UndirectedGraphNode(node -> label); //????
            for(auto x : node -> neighbors){ //for(int i = 0; i < node -> neighbors.size(); i++)
                (myMap[node] -> neighbors).push_back(cloneGraph(x));//recursion to clone all neighbors
            }
        }
        return myMap[node];
    }
};