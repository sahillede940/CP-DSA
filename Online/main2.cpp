#include <bits/stdc++.h>
using namespace std;

// STRONLY CONNECTED COMPONENTS ALGO (KOSARAJU'S ALGO)
bool dfs(int curr, int des, vector<vector<int>> &adj,
         vector<int> &vis)
{
    if (curr == des)
    {
        return true;
    }
    vis[curr] = 1;
    for (auto x : adj[curr])
    {
        if (!vis[x])
        {
            if (dfs(x, des, adj, vis))
            {
                return true;
            }
        }
    }
    return false;
}
bool isPath(int src, int des, vector<vector<int>> &adj)
{
    vector<int> vis(adj.size() + 1, 0);
    return dfs(src, des, adj, vis);
}
vector<vector<int>> findSCC(int n,
                            vector<vector<int>> &a)
{
    vector<vector<int>> ans;
    vector<int> is_scc(n + 1, 0);

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < a.size(); i++)
    {
        adj[a[i][0]].push_back(a[i][1]);
    }

    // Traversing all the vertices
    for (int i = 1; i <= n; i++)
    {

        if (!is_scc[i])
        {
            vector<int> scc;
            scc.push_back(i);

            for (int j = i + 1; j <= n; j++)
            {
                if (!is_scc[j] && isPath(i, j, adj) && isPath(j, i, adj))
                {
                    is_scc[j] = 1;
                    scc.push_back(j);
                }
            }
            ans.push_back(scc);
        }
    }
    return ans;
}

// MAIN FUNCTION

bool can_merge(const vector<int> &route, int i, int j, int k, const vector<int> &loc_cap)
{
    int total_demand = 0;

    // Calculate the total demand of the existing route
    for (int node : route)
    {
        total_demand += loc_cap[node];
    }

    // Add the demand of the new potential nodes
    total_demand += loc_cap[i] + loc_cap[j];

    // Check against capacity constraint
    return total_demand <= k;
}

int savings(int D_i, int D_j, int i_j)
{
    return D_i + D_j - i_j;
}

int main()
{
    // no of locations
    int num_loc;
    cin >> num_loc;

    // maximum capacity of the truck
    int k;
    cin >> k;

    // capacity of each location
    vector<int> loc_cap(num_loc + 1);
    for (int i = 1; i <= num_loc; i++)
    {
        cin >> loc_cap[i];
    }

    // distance between depots
    vector<vector<int>> depots(num_loc + 1, vector<int>(num_loc + 1, 0));
    for (int i = 0; i <= num_loc; i++)
    {
        for (int j = 0; j <= num_loc; j++)
        {
            cin >> depots[i][j];
        }
    }

    // Find the savings for each pair of depots
    vector<vector<pair<int, int>>> paths(num_loc + 1);
    for (int i = 1; i <= num_loc; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (i != j)
            {
                int saving = savings(depots[i][0], depots[0][j], depots[i][j]);
                if (saving >= 0)
                {
                    paths[i].push_back({saving, j});
                }
            }
        }
    }

    // Sort the savings in descending order
    // saving, {i, j} -> nodes
    vector<pair<int, pair<int, int>>> graph;
    for (int i = 1; i <= num_loc; i++)
    {
        for (auto x : paths[i])
        {
            graph.push_back({x.first, {i, x.second}});
        }
    }
    sort(graph.begin(), graph.end(), greater<pair<int, pair<int, int>>>());

    // Store connected components
    vector<vector<int>> routes;

    for (auto vv : graph)
    {
        int i = vv.second.first;
        int j = vv.second.second;
        int saving = vv.first;

        bool merged = false;
        // Try to merge with existing routes
        for (auto &route : routes)
        {
            if (can_merge(route, i, j, k, loc_cap))
            { // Implement the can_merge function
                route.push_back(i);
                route.push_back(j);
                merged = true;
                break;
            }
        }

        // Create a new route if no merge was possible
        if (!merged)
        {
            vector<int> new_route = {i, j};
            routes.push_back(new_route);
        }
    }

    findSCC(num_loc, routes);

    vector<vector<int> > ans = findSCC(num_loc, routes);
    cout << "Total Connected paths are:\n";
    for (auto x : ans) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << "\n";
    }

    return 0;
}
