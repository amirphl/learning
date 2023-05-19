// https://quera.org/contest/assignments/53487/problems/182488

#include "bits/stdc++.h"

using namespace std;

void func(int arr[], int query[][2], int n, int q, int k)
{
	int64_t prefix[n];
	int to[n];
	int from[n];
	prefix[0] = arr[0];
	memset(to, 0, sizeof(to));
	memset(from, 0, sizeof(from));

	for (int i = 1; i < n; i++) {
		prefix[i] = prefix[i - 1] + arr[i];
	}

	int64_t res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (i == 0) {
				if (abs(prefix[j]) <= k) {
					res++;
					from[i]++;
					to[j]++;
				}
			} else if (abs(prefix[j] - prefix[i - 1]) <= k) {
				res++;
				from[i]++;
				to[j]++;
			}
		}
	}

	cout << res << endl;

	for (int i = 0; i < q; i++) {
		int pos = query[i][0];
		int x = query[i][1];
		int frst_prev = arr[pos];
		int sec_prev = arr[pos + 1];
		arr[pos] += x;
		arr[pos + 1] -= x;
		int64_t s = 0;
		int c = 0;

		for (int j = pos; j >= 0; j--) {
			s += arr[j];
			if (abs(s) <= k) {
				c++;
			}
		}
		for (int j = pos + 1; j < n; j++) {
			int a = prefix[j] - prefix[pos];
			int b =
			    prefix[j] - prefix[pos] + arr[pos + 1] - sec_prev;
			if (k < abs(a) && abs(b) <= k) {
				to[j]++;
			}
			if (abs(a) <= k && k < abs(b)) {
				to[j]--;
			}
		}

		int diff = c - to[pos];
		res += diff;
		to[pos] = c;

		s = 0;
		c = 0;

		for (int j = 0; j <= pos; j++) {
			int a, b;
			if (j > 0) {
				a = prefix[pos] - prefix[j - 1];
				b = a + arr[pos] - frst_prev;
			} else {
				a = prefix[pos];
				b = a + arr[pos] - frst_prev;
			}

			if (k < abs(a) && abs(b) <= k) {
				from[j]++;
			}
			if (abs(a) <= k && k < abs(b)) {
				from[j]--;
			}
		}
		for (int j = pos + 1; j < n; j++) {
			s += arr[j];
			if (abs(s) <= k) {
				c++;
			}
		}

		diff = c - from[pos + 1];
		res += diff;
		from[pos + 1] = c;

		prefix[0] = arr[0];
		for (int i = 1; i < n; i++) {
			prefix[i] = prefix[i - 1] + arr[i];
		}

		cout << res << endl;
	}
}

int main()
{
	int n, k, q;
	cin >> n >> k >> q;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int query[q][2];
	for (int i = 0; i < q; i++) {
		cin >> query[i][0];
		query[i][0]--;
		cin >> query[i][1];
	}
	func(arr, query, n, q, k);
	return 0;
}
