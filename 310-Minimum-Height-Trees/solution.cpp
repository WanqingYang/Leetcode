/**BFS 要建立一个图g，是一个二维数组，其中g[i]是一个一维数组，保存了i节点可以到达的所有节点。还需要一个一维数组d用来保存各个节点的入度信息，其中d[i]表示i节点的入度数。我们的目标是删除所有的叶节点，叶节点的入度为1，所以我们开始将所有入度为1的节点(叶节点)都存入到一个队列queue中，然后我们遍历每一个叶节点，通过图来找到和其相连的节点，将该节点的入度减1，如果该节点的入度减到1了，说明此节点也也变成一个叶节点了，加入队列中，再下一轮删除。那么我们删到什么时候呢，当节点数小于等于2时候停止，此时剩下的一个或两个节点就是我们要求的最小高度树的根节点
 **/
//use vector<unordered_set<int>> graph
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> res;
        if(edges.empty()) {
            res.push_back(0);
            return res; 
        }
        vector<unordered_set<int>> graph(n, unordered_set<int>());
        //vector<vector<unordered_set<int>> graph(n);
        vector<int> degree(n, 0);
        
        //make grph
        for(auto a: edges) {
            graph[a.first].insert(a.second);
            degree[a.first]++;
            graph[a.second].insert(a.first);
            degree[a.second]++;
        }
        //push node with degree 1 to queue
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(degree[i] == 1) {q.push(i);}
        }
        
        while(n > 2) {
            int _size = q.size();
            for(int i = 0; i < _size; i++) {
                int f = q.front();
                q.pop();
                n--;
                for(auto it = graph[f].begin(); it != graph[f].end(); it++) {
                    degree[*it]--;
                    if(degree[*it] == 1) {q.push(*it);graph[f].erase(*it);}
                    //graph[f].erase(*it);
                }
            }
        }
        while(!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};

//use vector<vector<int>> graph
