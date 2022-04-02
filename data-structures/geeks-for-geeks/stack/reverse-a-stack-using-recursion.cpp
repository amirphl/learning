// https://www.geeksforgeeks.org/reverse-a-stack-using-recursion/
// https://www.geeksforgeeks.org/reverse-stack-without-using-extra-space/

#include<bits/stdc++.h>
#include<iostream>

void insert_bot(std::stack<int> &s, int elem) {
	if (s.empty()) {
		s.push(elem);
		return;
	}

	int a = s.top();
	s.pop();
	insert_bot(s, elem);
	s.push(a);
}

void reverse(std::stack<int> &s) {
	if (s.empty())
		return;
	int a = s.top();
	s.pop();
	reverse(s);
	insert_bot(s, a);
}

// time: O(n*n), memory: O(n)
int main() {
	int arr[] = {1, 5 ,4 ,3 ,-1 ,4 ,2, 0, 4, 8};
	int n = sizeof(arr) / sizeof(arr[0]);
	std::stack<int> s;
	for (int i = 0; i < n; i++)
		s.push(arr[i]);
	reverse(s);
	for (int i = 0; i < n; i++) {
		std::cout << s.top() << " ";
		s.pop();
	}
	return 0;
}
