// https://leetcode.com/problems/number-of-orders-in-the-backlog/

class Solution {
public:
    int mod = 1e9 + 7;

    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> sell;
        priority_queue<vector<int>> buy;
        uint64_t total_orders = 0;

        for(auto& order: orders) {
            if (order[2] == 0) { // buy
                if (sell.empty()) {
                    total_orders += order[1];
                    buy.push(order);
                    continue;
                }

                int lowest_price = sell.top()[0];

                while(lowest_price <= order[0]) {
                    int amount = sell.top()[1];

                    if (amount <= order[1]) {
                        // cout << "pop l " << lowest_price << endl;
                        total_orders -= amount;
                        sell.pop();
                        order[1] -= amount;
                        lowest_price = sell.empty() ? INT_MAX : sell.top()[0];
                    } else {
                        int p = sell.top()[0];
                        int new_amount = amount - order[1];
                        order[1] = 0;
                        total_orders -= amount;
                        sell.pop();
                        total_orders += new_amount;
                        sell.push({p, new_amount, 1});
                        // cout << "push s " << p << " " << new_amount << endl;
                        break;
                    }
                }

                if (order[1] > 0) {
                    total_orders += order[1];
                    buy.push(order);
                }
            } else {
                if (buy.empty()) {
                    total_orders += order[1];
                    sell.push(order);
                    continue;
                }

                int highest_price = buy.top()[0];

                while(order[0] <= highest_price) {
                    int amount = buy.top()[1];

                    if (amount <= order[1]) {
                        // cout << "pop h " << highest_price << endl;
                        total_orders -= amount;
                        buy.pop();
                        order[1] -= amount;
                        highest_price = buy.empty() ? INT_MIN : buy.top()[0];
                    } else {
                        int p = buy.top()[0];
                        int new_amount = amount - order[1];
                        order[1] = 0;
                        total_orders -= amount;
                        buy.pop();
                        total_orders += new_amount;
                        buy.push({p, new_amount, 0});
                        // cout << "push b " << p << " " << new_amount << endl;
                        break;
                    }
                }

                if (order[1] > 0) {
                    total_orders += order[1];
                    sell.push(order);
                }
            }
        }

        return total_orders % mod;
    }
};
