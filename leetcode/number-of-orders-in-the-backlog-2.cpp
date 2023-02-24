// https://leetcode.com/problems/number-of-orders-in-the-backlog/

class Solution {
public:
    int mod = 1e9 + 7;

    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        set<vector<int>> sell;
        set<vector<int>> buy;
        uint64_t total_orders = 0;

        for(auto& order: orders) {
            if (order[2] == 0) { // buy
                if (sell.empty()) {
                    total_orders += order[1];
                    buy.insert(order);
                    continue;
                }

                auto it = sell.begin();
                int lowest_price = it -> at(0);

                while(lowest_price <= order[0]) {
                    int amount = it -> at(1);

                    if (amount <= order[1]) {
                        // cout << "pop l " << lowest_price << endl;
                        total_orders -= amount;
                        sell.erase(it);
                        order[1] -= amount;
                        it = sell.empty() ? it : sell.begin();
                        lowest_price = sell.empty() ? INT_MAX : it -> at(0);
                    } else {
                        int p = it -> at(0);
                        int new_amount = amount - order[1];
                        order[1] = 0;
                        total_orders += new_amount - amount;
                        sell.erase(it);
                        sell.insert({p, new_amount, 1});
                        // cout << "push s " << p << " " << new_amount << endl;
                        break;
                    }
                }

                if (order[1] > 0) {
                    total_orders += order[1];
                    buy.insert(order);
                }
            } else {
                if (buy.empty()) {
                    total_orders += order[1];
                    sell.insert(order);
                    continue;
                }

                auto it = buy.end();
                it--;
                int highest_price = it -> at(0);

                while(order[0] <= highest_price) {
                    int amount = it -> at(1);

                    if (amount <= order[1]) {
                        // cout << "pop h " << highest_price << endl;
                        total_orders -= amount;
                        buy.erase(it);
                        order[1] -= amount;
                        it = buy.empty() ? it : --buy.end();
                        highest_price = buy.empty() ? INT_MIN : it -> at(0);
                    } else {
                        int p = it -> at(0);
                        int new_amount = amount - order[1];
                        order[1] = 0;
                        total_orders += new_amount - amount;
                        buy.erase(it);
                        buy.insert({p, new_amount, 0});
                        // cout << "push b " << p << " " << new_amount << endl;
                        break;
                    }
                }

                if (order[1] > 0) {
                    total_orders += order[1];
                    sell.insert(order);
                }
            }
        }

        return total_orders % mod;
    }
};
