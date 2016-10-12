class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        for(auto ticket: tickets) {
            graph[ticket.first].insert(ticket.second);
        }
        dfs("JFK");
        return vector<string>(res.rbegin(), res.rend());
    }
private:
    map<string, multiset<string>> graph;
    vector<string> res;
    
    void dfs(string airport) {
        while(!graph[airport].empty()) {
            string next = *graph[airport].begin();
            graph[airport].erase(graph[airport].begin());
            dfs(next);
        }
        res.push_back(airport);
        return;
    }
};