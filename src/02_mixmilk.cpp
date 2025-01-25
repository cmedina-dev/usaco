//
// Created by cmedina on 1/24/2025.
// https://usaco.org/index.php?page=viewproblem2&cpid=855
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);

    vector<pair<int, int>> milk_cap_store;

    for (int i = 0; i < 3; i++) {
        pair<int, int> milk_cap;
        cin >> milk_cap.first >> milk_cap.second;
        milk_cap_store.push_back(milk_cap);
    }

    int src = 0;
    int tgt = 1;
    for (int i = 0; i < 100; i++) {
        const int tgt_remaining_cap = milk_cap_store[tgt].first - milk_cap_store[tgt].second;
        const int amt = min(milk_cap_store[src].second, tgt_remaining_cap);
        milk_cap_store[src].second -= amt;
        milk_cap_store[tgt].second += amt;

        src++;
        tgt++;
        if (tgt > 2) {
            tgt = 0;
        }
        if (src > 2) {
            src = 0;
        }
    }

    for (auto bucket : milk_cap_store) {
        cout << bucket.second << '\n';
    }

    return 0;
}