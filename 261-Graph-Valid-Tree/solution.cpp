/**To tell whether a graph is a valid tree, we have to:
- Make sure there is no cycle in the graph - this has to be a none-cyclic graph;
- Make sure every node is reached - this has to be a connected graph;
 **/

class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> nodes(n, 0);
        for(int i = 1; i < n; i++) {
            nodes[i] = i; //union name
        }
        for(int i = 0; i < edges.size(); i++) {
            int f = edges[i].first;
            int s = edges[i].second;
            //cout << "f , s = " << f << s << endl;
            if(nodes[f] != f) {f = nodes[f];} //give a smaller value, it is union name, where this origin node is
            if(nodes[s] != s) {s = nodes[s];}
            //cout << " f , s = " << f << s << endl;
            //if(s == f) {return false;}
            if(nodes[s] == nodes[f]) {return false;}
            //nodes[s] = nodes[f]; //this is wrong
            nodes[s] = f;
        }
        return edges.size() == n - 1;
    }
};