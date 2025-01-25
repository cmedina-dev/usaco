//
// Created by cmedina on 1/24/2025.
// https://usaco.org/index.php?page=viewproblem2&cpid=665
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);

    int m, n, k;
    cin >> m >> n >> k;
    vector<string> final_string;

    for (int i = 0; i < m; i++) {
        string str;
        vector<char> new_string(n * k);
        cin >> str;
        for (int j = 0; j < n * k; j += k) {
            for (int l = j; l < j + k; l++) {
                const int ptr = j / k;
                new_string[l] = str[ptr];
            }
        }
        for (int j = 0; j < k; j++) {
            final_string.emplace_back(new_string.begin(), new_string.end());
        }
    }

    for (const auto& str : final_string) {
        cout << str << '\n';
    }

    return 0;
}
