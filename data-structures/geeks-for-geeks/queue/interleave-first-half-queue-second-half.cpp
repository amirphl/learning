// https://www.geeksforgeeks.org/interleave-first-half-queue-second-half/

#include<bits/stdc++.h>
#include<iostream>

void insert(std::queue<int> &q, int elem, int pos) {
	int n = q.size() - pos + 1;
	while(n > 0) {
		n--;
		q.push(q.front());
		q.pop();
	}
	q.push(elem);
	n = pos - 1;
	while(n > 0) {
		n--;
		q.push(q.front());
		q.pop();
	}
}

// time: O(n*n), memory: O(n)
void interleave(std::queue<int> &q, std::stack<int> &s, int n) {
	while (q.size() > n / 2) {
		s.push(q.front());
		q.pop();
	}
	int pos = 2;
	while(!s.empty()) {
		insert(q, s.top(), pos);
		s.pop();
		pos += 2;
	}
}

// time: O(n), memory: O(n)
void interleave2(std::queue<int> &q, std::stack<int> &s, int n) {
	while(q.size() > n / 2) {
		s.push(q.front());
		q.pop();
	}
	while(!s.empty()) {
		q.push(s.top());
		s.pop();
	}
	int i = 0;
	while(i < n / 2) {
		i++;
		q.push(q.front());
		q.pop();
	}
	while(q.size() > n / 2) {
		s.push(q.front());
		q.pop();
	}
	i = 0;
	while(i < n / 2) {
		i++;
		q.push(s.top());
		q.push(q.front());
		s.pop();
		q.pop();
	}
}

int main() {
	std::queue<int> q;
	std::stack<int> s;
	q.push(1);
	q.push(5);
	q.push(7);
	q.push(2);
	q.push(10);
	q.push(4);
	q.push(-1);
	q.push(0);
	// interleave(q, s, q.size());
	interleave2(q, s, q.size());
	while(!q.empty()) {
		std::cout << q.front() << " ";
		q.pop();
	}
	return 0;
}
