//
// Created by cmedina on 1/24/2025.
// https://usaco.org/index.php?page=viewproblem2&cpid=891
//

#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    int n;
    cin >> n;

    vector shells = {0, 0, 0};
    int max_shell = 0;
    for (int i = 0; i < n; i++) {
        int a, b, g;
        cin >> a >> b >> g;
        swap(shells[a-1], shells[b-1]);
        shells[g-1]++;
        max_shell = max(max_shell, shells[g-1]);
    }

    cout << max_shell << '\n';
    return 0;
}
