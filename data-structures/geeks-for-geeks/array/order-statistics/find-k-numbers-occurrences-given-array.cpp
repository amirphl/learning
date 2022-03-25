// https://www.geeksforgeeks.org/find-k-numbers-occurrences-given-array/
// TODO(amirphl) https://www.geeksforgeeks.org/find-k-most-frequent-in-linear-time/

// { Driver Code Starts
#include <bits/stdc++.h>

 // } Driver Code Ends
class Solution {
	public:
	// time: O(nlogn), memory: O(n)
	std::vector<int> topK(std::vector<int>& nums, int k) {
		std::map<int, int> m;
		int n = nums.size();

		for (int i = 0; i < n; i++)
			m[nums[i]]++;

		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> min_heap;
		int counter = 0;

		for(auto it = m.begin(); it != m.end(); it++, counter++){
			std::pair<int, int> ne(it -> second, it -> first);

			if (counter < k) {
				min_heap.push(ne);
				continue;
			}

			std::pair<int, int> top = min_heap.top();

			if (top.first < ne.first || (top.first == ne.first && top.second < ne.second)) {
				min_heap.pop();
				min_heap.push(ne);
			}
		}

		std::vector<int> res(k);
		counter = k - 1;

		while(!min_heap.empty()) {
			// std::cout << min_heap.top().second << " " << min_heap.top().first << std::endl;
			res[counter] = min_heap.top().second;
			min_heap.pop();
			counter--;
		}

		return res;
	}
};


// { Driver Code Starts.
int main() {
    int tc;
    std::cin >> tc;
    while (tc--) {
        int n;
	std::cin >> n;
	std::vector<int> nums(n);
        for (auto &i : nums) std::cin >> i;
        int k;
	std::cin >> k;
        Solution obj;
	std::vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) std::cout << i << " ";
	std::cout << "\n";
    }
    return 0;
}  // } Driver Code Ends
