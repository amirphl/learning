// https://www.geeksforgeeks.org/sort-elements-by-frequency/
// https://www.geeksforgeeks.org/sort-elements-by-frequency-set-2/
// https://www.geeksforgeeks.org/sort-elements-frequency-set-4-efficient-approach-using-hash/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// time: O(n + mlogm), memory: O(m)
// m: #unique elements in arr
void sort(int arr[], int n) {
    unordered_map<int, int> freq;
    int i = 0;
    while(i < n) {
        freq[arr[i]]++;
        i++;
    }
    array<int, 2> temp[freq.size()];
    i = 0;
    for(auto& p: freq) {
        temp[i] = {p.second, p.first};
        i++;
    }
    auto comp = [](const array<int, 2>& u, const array<int, 2>& v) {
        if (u[0] > v[0]) {
            return true;
        } else if (u[0] == v[0]) {
            return u[1] < v[1];
        } else {
            return false;
        }
    };
    sort(temp, temp + freq.size(), comp);
    i = 0;
    int j = 0;
    while(i < freq.size()) {
        // cout << temp[i][0] << " " << temp[i][1] << endl;
        while(temp[i][0] > 0) {
            arr[j] = temp[i][1];
            temp[i][0]--;
            j++;
        }
        i++;
    }
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main() {
	int t, n, m;
	std::cin >> t;
	while(--t >= 0) {
        std::cin >> n;
        m = n;
        int arr[m];
        while(--n >= 0)
            std::cin >> arr[n];
        sort(arr, m);
        print(arr, m);
	}
	return 0;
}
