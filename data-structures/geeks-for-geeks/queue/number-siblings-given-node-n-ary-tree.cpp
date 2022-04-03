// https://www.geeksforgeeks.org/number-siblings-given-node-n-ary-tree/

// This is a more comprehensive implementation. All siblings are printed.

#include<bits/stdc++.h>
#include<iostream>

// time: O(V + E), memory: O(V)
int main() {
	int n = 28;
	int arr[n][n];
	std::memset(arr, 0, sizeof(arr));
	arr[0][1] = 1;
	arr[0][2] = 1;
	arr[0][3] = 1;
	arr[1][4] = 1;
	arr[1][5] = 1;
	arr[1][6] = 1;
	arr[1][7] = 1;
	arr[2][8] = 1;
	arr[2][9] = 1;
	arr[3][10] = 1;
	arr[4][11] = 1;
	arr[4][12] = 1;
	arr[7][13] = 1;
	arr[7][14] = 1;
	arr[9][15] = 1;
	arr[9][16] = 1;
	arr[14][17] = 1;
	arr[17][18] = 1;
	arr[18][19] = 1;
	arr[18][20] = 1;
	arr[20][21] = 1;
	arr[20][22] = 1;
	arr[20][23] = 1;
	arr[22][24] = 1;
	arr[24][25] = 1;
	arr[25][26] = 1;
	arr[25][27] = 1;

	std::vector<std::vector<int>> adj;

	for(int i = 0; i < n; i++) {
		std::vector<int> r;
		for(int j = 0; j < n; j++)
			if (arr[i][j] == 1)
				r.push_back(j);
		adj.push_back(r);
	}

	// print siblings of all nodes
	for(int k = 0; k < n; k++) {
		std::queue<int> q;
		std::queue<int> sib; // It stores the siblings at each level of the tree.
		q.push(0);
		int last = 0, temp; // last: last element of each level
		int dst = k; // print siblings of `dst` at current iteration.
		int reached = 0; // reached `dst` or not.

		while(!q.empty()) {
			int top = q.front();
			q.pop();
			sib.push(top);
			for(int i = 0; i < adj[top].size(); i++)
				q.push(adj[top][i]);
			if (dst == top)
				reached = 1;
			if (!adj[top].empty())
				temp = adj[top][adj[top].size() - 1];
			if (top == last) {
				if (reached == 1)
					break;
				std::queue<int> empty;
				std::swap(sib, empty);
				last = temp;
				temp = -1;
				// std::cout << last << " ";
			}
		}

		std::cout << "siblings of " << dst << ": ";
		while(!sib.empty()) {
			std::cout << sib.front() << " ";
			sib.pop();
		}
		std::cout << std::endl;
	}
	return 0;
}
