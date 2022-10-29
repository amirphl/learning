// https://www.geeksforgeeks.org/generate-all-possible-sorted-arrays-from-alternate-elements-of-two-given-arrays/

#include<bits/stdc++.h>

using namespace std;

void generate_rec(int arr_1, int arr_2, int n1, int n2, int s1, int s2, stack<int>& cache) {
    int i = s1;
    while(i < n1) {
        int j = distance(arr_2, lower_bound(arr_2, arr_2 + n2, arr_1[i]));
        while(j < n2) {
            generate_rec(arr_1, arr_2, n1, n2, i, j, res);
            j++;
        }
        i++;
    }
}

void generate(int arr_1[], int arr_2[], int n1, int n2) {
    vector<vector<int>> res;
    generate_rec(arr_1, arr_2, n1, n2, 0, 0, res);
    for(auto& v: res) {
        for(auto& elem: v) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while(--t >= 0) {
        int n1, n2;
        cin >> n1 >> n2;
        int arr_1[n1], arr_2[n2];
        int i = 0;
        while(--n1 > 0) {
            cin >> arr_1[i];
            i++;
        }
        i = 0;
        while(--n2 > 0) {
            cin >> arr_2[i];
            i++;
        }
        sort(arr_1, arr_1 + n);
        sort(arr_2, arr_2 + n);
        generate(arr_1, arr_2, n1, n2);
    }

    return 0;
}
