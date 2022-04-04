// https://www.geeksforgeeks.org/sorting-queue-without-extra-space/

#include<bits/stdc++.h>
#include<iostream>

// time: O(n*n), memory: O(1)
void sort(std::queue<int> &q) {
	int n = q.size();
	int i = 0, j, min, index;
	while(i < n - 1) {
		j = n - 1 - i;
		min = q.front();
		index = j;
		// find `ith` min
		while(j >= 0) {
			// std::cout << q.front() << " ";
			if (min > q.front()) {
				min = q.front();
				index = j;
			}
			q.push(q.front());
			q.pop();
			j--;
		}
		j = i;
		while(j > 0) {
			// std::cout << q.front() << " ";
			q.push(q.front());
			q.pop();
			j--;
		}
		// std::cout << std::endl << "min " << min << " index " << index << std::endl;
		// put the `ith` min in the right position
		j = 0;
		while(j < n + 1) {
			if (j == n - i - index - 1) {
				// std::cout << "j " << j << " pop min " << q.front() << std::endl;
				q.pop();
			} else if (j == n - i) {
				// std::cout << "j " << j << " push min " << min << std::endl;
				q.push(min);
			} else {
				// std::cout << "j " << j << " i " << q.front() << std::endl;
				q.push(q.front());
				q.pop();
			}
			j++;
		}
		// std::cout << "----------" << std::endl;
		i++;
	}
}

int main() {
	std::queue<int> q;
	q.push(7);
	q.push(4);
	q.push(1);
	q.push(0);
	q.push(2);
	q.push(5);
	q.push(5);
	q.push(5);
	q.push(-4);
	q.push(50);
	q.push(6);
	q.push(9);
	q.push(8);
	sort(q);
	while(!q.empty()) {
		std::cout << q.front() << " ";
		q.pop();
	}
	std::cout << std::endl;
	return 0;
}
