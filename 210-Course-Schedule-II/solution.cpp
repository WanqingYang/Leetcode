class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<bool> onpath(numCourses, false);
        vector<bool> visited(numCourses, false);
        vector<int> res;
        
        for(int i = 0; i < numCourses; i++) {
            if(!visited[i] && dfs_cycle(graph, i, onpath, visited, res)){
                return {};
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }

private:    
    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for(auto pre: prerequisites) {
            graph[pre.second].insert(pre.first);
        }
        return graph;
    }
    
    bool dfs_cycle(vector<unordered_set<int>> &graph, int node, vector<bool> &onpath, 
    vector<bool> &visited, vector<int> &res) {
        if(visited[node] == true){return false;}
        visited[node] = onpath[node] = true;
        
        for(int neigh: graph[node]) {
            if(onpath[neigh] || dfs_cycle(graph, neigh, onpath, visited, res)){
                return true;
            }
        }
        res.push_back(node);//not push_back neigh, for neighs are node's pres
        return onpath[node] = false;
    }
};