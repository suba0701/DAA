#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Item {
    int id;
    int profit;
    int weight;
    double ratio;
};

struct Node {
    int level;
    int profit;
    int weight;
    double bound;
};

bool compareItems(Item a, Item b) {
    return a.ratio > b.ratio;
}

struct CompareNodes {
    bool operator()(Node const& n1, Node const& n2) {
        return n1.bound < n2.bound;
    }
};

double calculateBound(Node u, int n, int W, vector<Item>& items) {
    if (u.weight >= W) return 0;
    double profit_bound = u.profit;
    int j = u.level + 1;
    int total_weight = u.weight;
    while (j < n && total_weight + items[j].weight <= W) {
        total_weight += items[j].weight;
        profit_bound += items[j].profit;
        j++;
    }
    if (j < n)
        profit_bound += (W - total_weight) * items[j].ratio;
    return profit_bound;
}

void solveKnapsack(int W, vector<Item>& items) {
    int n = items.size();
    sort(items.begin(), items.end(), compareItems);

    priority_queue<Node, vector<Node>, CompareNodes> pq;
    Node u, v;

    u.level = -1; u.profit = 0; u.weight = 0;
    u.bound = calculateBound(u, n, W, items);
    pq.push(u);

    int maxProfit = 0;
    int totalWeightAtMax = 0;

    while (!pq.empty()) {
        u = pq.top();
        pq.pop();

        if (u.level == n - 1 || u.bound <= maxProfit) continue;

        v.level = u.level + 1;


        v.weight = u.weight + items[v.level].weight;
        v.profit = u.profit + items[v.level].profit;

        if (v.weight <= W) {
            if (v.profit > maxProfit) {
                maxProfit = v.profit;
                totalWeightAtMax = v.weight;
            }
        }

        v.bound = calculateBound(v, n, W, items);
        if (v.bound > maxProfit) pq.push(v);


        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = calculateBound(v, n, W, items);

        if (v.bound > maxProfit) pq.push(v);
    }

    cout << "\n--- Result ---" << endl;
    cout << "Maximum Profit: " << maxProfit << endl;
    cout << "Total Weight: " << totalWeightAtMax << endl;
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter Knapsack capacity: ";
    cin >> W;

    vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        items[i].id = i + 1;
        cout << "Enter profit and weight for item " << i + 1 << ": ";
        cin >> items[i].profit >> items[i].weight;
        items[i].ratio = (double)items[i].profit / items[i].weight;
    }

    solveKnapsack(W, items);

    return 0;
}
