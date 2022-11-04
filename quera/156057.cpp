// https://quera.org/contest/assignments/45359/problems/156057
// score: 95

#include<bits/stdc++.h>

using namespace std;

void print_res(int b[], int end) {
    cout << end + 1 << "\n";
    int i = 0;
    while(i <= end) {
        cout << b[i] << " ";
        i++;
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    int **arr = new int*[t];
    int s[t];
    int i = 0;
    while(i < t) {
        int m;
        cin >> m;
        int *b = new int[m];
        arr[i] = b;
        s[i] = m;
        int j = 0;
        while(j < m) {
            cin >> b[j];
            j++;
        }
        i++;
    }

    int ctr = 0;
    while(ctr < t) {
        int m = s[ctr];
        int *b = arr[ctr];
        int end = -1;

        i = 1;
        while(i < m) {
            if (b[i] == b[0]) {
                int cand_end = i - 1;
                int j = 0;
                while(i < m) {
                    if (b[i] == b[j]) {
                        i++;
                        j++;
                        j %= (cand_end + 1);
                    } else {
                        break;
                    }
                }
                if (i == m) {
                    end = cand_end;
                    print_res(b, cand_end);
                    break;
                } else {
                    // first submission: remove this line:
                    i = cand_end + 2;
                }
            } else {
                i++;
            }
        }
        if (end == -1) {
            print_res(b, m - 1);
        }

        // delete(b)
        ctr++;
    }
    // delete(arr)

    return 0;
}
