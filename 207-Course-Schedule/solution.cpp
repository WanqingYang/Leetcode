//if cycle exsist, it is impossible
//mycode; wrong
/*class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if(numCourses == 0 || prerequisites.empty()){
            return true;
        }
        
        unordered_map<int, vector<int>> checkMap;//store every courese's prerequisites
        for(int i = 0; i < prerequisites.size(); i++){
            int pair0 = get<0>(prerequisites[i]);
            int pair1 = get<1>(prerequisites[i]);
            
            if(checkMap.find(pair1) != checkMap.end()){//if pair (<1>,<>) exist
                //traverse the checkMap[], to check if the cycle exist
                for(int j = 0; j < checkMap[pair1].size(); j++){
                    if(checkMap[pair1][j] == pair0){
                        return false;
                    }
                }
            }
            
            if(checkMap.find(pair0) == checkMap.end()){//(<0>, <>) is not exist
                checkMap[pair0] =  vector<int>(1, pair1);
            }else{
                checkMap[pair0].push_back(pair1);
            }
        }
        return true;
    }
};*/

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<bool> onpath(numCourses, false), visited(numCourses, false);
        for (int i = 0; i < numCourses; i++)
            if (!visited[i] && dfs_cycle(graph, i, onpath, visited))
                return false;
        return true;
    }
private:
    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for (auto pre : prerequisites)
            graph[pre.second].insert(pre.first);
        return graph;
    } 
    bool dfs_cycle(vector<unordered_set<int>>& graph, int node, vector<bool>& onpath, vector<bool>& visited) {
        if (visited[node]) return false;
        onpath[node] = visited[node] = true; 
        for (int neigh : graph[node])
            if (onpath[neigh] || dfs_cycle(graph, neigh, onpath, visited))
                return true;
        return onpath[node] = false;
    }
};