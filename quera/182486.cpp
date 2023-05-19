// https://quera.org/contest/assignments/53487/problems/182486

#include "bits/stdc++.h"

using namespace std;

int compute(int arr[4])
{
	int res = 0;
	for (int j = 1; j < 4; j++)
		for (int i = j + 1; i < 4; i++) {
			if (arr[i] > arr[j]) {
				res++;
			}
		}
	return res;
}

int main()
{
	int n;
	cin >> n;
	int arr[4 * n];
	for (int i = 0; i < 4 * n; i++) {
		cin >> arr[i];
	}
	// cout << "----\n";
	int a, b, c, d;
	int fff[4];
	for (int i = 0; i < n; i++) {
		int r = INT_MAX;
		a = arr[4 * i + 0];
		b = arr[4 * i + 1];
		c = arr[4 * i + 2];
		d = arr[4 * i + 3];

		fff[0] = a;
		fff[1] = b;
		fff[2] = c;
		fff[3] = d;
		r = min(r, compute(fff));
		fff[0] = b;
		fff[1] = a;
		fff[2] = c;
		fff[3] = d;
		r = min(r, compute(fff));
		fff[0] = c;
		fff[1] = a;
		fff[2] = b;
		fff[3] = d;
		r = min(r, compute(fff));
		fff[0] = d;
		fff[1] = a;
		fff[2] = b;
		fff[3] = c;
		r = min(r, compute(fff));
		cout << r << "\n";
	}
	return 0;
}
