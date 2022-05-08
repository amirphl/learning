// https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/

// Time Complexity: O(ElogE) or O(ElogV). Sorting of edges takes O(ELogE) time. After sorting, we iterate through all edges and apply the find-union algorithm. The find and union operations can take at most O(LogV) time. So overall complexity is O(ELogE + ELogV) time. The value of E can be at most O(V2), so O(LogV) is O(LogE) the same. Therefore, the overall time complexity is O(ElogE) or O(ElogV)


#include <bits/stdc++.h>
using namespace std;
// DSU data structure
// path compression + rank by union

class DSU {
	int* parent;
	int* rank;

    public:
	DSU(int n)
	{
        parent = new int[n];
        rank = new int[n];
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
        memset(rank, 0, n);
	}

	// Find function
    // time: O(log(|V|))
	int find(int i)
	{
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
	}
	// union function
	void unite(int x, int y)
	{
        int xroot = find(x);
        int yroot = find(y);
        if (rank[xroot] < rank[yroot]) {
            parent[xroot] = yroot;
        } else if (rank[xroot] > rank[yroot]) {
            parent[yroot] = xroot;
        } else {
            parent[yroot] = xroot;
            rank[xroot]++;
        }
	}
};

class Graph {
	vector<vector<int> > edgelist;
	int V;

    public:
	Graph(int V) { this->V = V; }

	void addEdge(int x, int y, int w)
	{
		edgelist.push_back({ w, x, y });
	}

    // time: O(|E|log(|E|) + |E|log(|V|)), memory: O(|V|)
	void kruskals_mst()
	{
        vector<vector<int>> mst;
        DSU dsu(V);
        sort(edgelist.begin(), edgelist.end());
        int c = 0, i = 0;
        while(c < V - 1 && i < edgelist.size()) {
            int xroot = dsu.find(edgelist[i][1]);
            int yroot = dsu.find(edgelist[i][2]);
            if (xroot != yroot) {
                dsu.unite(xroot, yroot);
                mst.push_back(edgelist[i]);
                c++;
            }
            i++;
        }
        for(auto it = mst.begin(); it != mst.end(); it++) {
            cout << (*it)[0] << " " << (*it)[1] << " " << (*it)[2] << endl;
        }
    }
};
int main()
{
	/* Let us create following weighted graph
				10
			0--------1
			| \	 |
			6| 5\ |15
			|	 \ |
			2--------3
				4	 */
	Graph g(4);
	g.addEdge(0, 1, 10);
	g.addEdge(1, 3, 15);
	g.addEdge(2, 3, 4);
	g.addEdge(2, 0, 6);
	g.addEdge(0, 3, 5);

	// int n, m;
	// cin >> n >> m;

	// Graph g(n);
	// for (int i = 0; i < m; i++)
	// {
	//	 int x, y, w;
	//	 cin >> x >> y >> w;
	//	 g.addEdge(x, y, w);
	// }

	g.kruskals_mst();
	return 0;
}

