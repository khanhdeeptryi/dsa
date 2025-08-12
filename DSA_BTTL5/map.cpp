//
// Created by phamq on 8/6/2025.
//
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct Graph {
    vector<string> vertices;
    unordered_map<string, unordered_map<string, int>> adj_list;

    void them_canh (string u, string i, int w) {
        adj_list[u][i] = w;
    }

    void dump() {
        for (auto cells : adj_list) {
            cout << cells.first << ": (";
            for (auto ke : cells.second) {
                cout << ke.first << "->" << ke.second << ", ";
            }
            cout << ")\n";
        }
    }

    bool is_adjacent(string u, string i) {
        return adj_list[u].count(i);
    }

    int edge_weight(string u, string i) {
        if (is_adjacent(u, i)) return adj_list[u][i];
        throw runtime_error(u + " va " + i + "ko ke`");
    }

    void list_adjacent_edges(string u) {
        vector<pair<int, int>> result;
        for (auto ke : adj_list[u]) {
            result.push_back({name_to_index[ke.first], ke.second});
        }
        sort(result.begin(), result.end());
        return result;
    }

    bool search(string s, string g) {
        queue<string> open;
        unordered_set<string> close;
        open.push(s);
        while (open.empty() == false) {
            auto p = open.front();
            if (p == g) return true;
            close.insert(p);
            for (auto q : adj_list[p]) {
                if (close.count(q) == 0) {
                    open.push(q);
                }
            }
        }
        return false;
    }
};

int main() {
    int v, e, n;
    cin >> v >> e >> n;
    Graph g;
    g.vertices = vector<string>(v);
    for (auto &v : g.vertices) cin >> v;
    while (e--) {
        string u, i;
        int w;
        cin >> u >> i >> w;
        g.them_canh(u, i, w);
        g.dump();
    }
}