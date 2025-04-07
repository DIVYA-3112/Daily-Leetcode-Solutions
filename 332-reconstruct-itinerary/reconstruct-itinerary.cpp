class Solution {
public:
    unordered_map<string, multiset<string>> graph;
    vector<string> itinerary;

    void dfs(string node) {
        auto &dests = graph[node];
        while (!dests.empty()) {
            string next = *dests.begin(); // lex smallest
            dests.erase(dests.begin());
            dfs(next);
        }
        itinerary.push_back(node); // add when done with all edges
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto &ticket : tickets) {
            graph[ticket[0]].insert(ticket[1]);
        }

        dfs("JFK");
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};
