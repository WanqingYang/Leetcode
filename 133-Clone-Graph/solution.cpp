/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
 
 /**Create a new node if the node map doesn't already contain a node with this label, 
  * otherwise return the pointer to the node with that label from the node map. 
  * Add the children to new nodes recursively through BFS.
  **/
class Solution {
private: unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> myMap;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node){return node;}//base case
        if(myMap.find(node) == myMap.end()){//node is not in myMap
            myMap[node] = new UndirectedGraphNode(node -> label); //????
            for(auto x : node -> neighbors){ //for(int i = 0; i < node -> neighbors.size(); i++)
                (hash[node] -> neighbors).push_back(cloneGraph(x));
            }
        }
        return hash[node];
    }
};