//
// Created by cmedina on 1/24/2025.
// https://usaco.org/index.php?page=viewproblem2&cpid=568
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    int N, M;
    cin >> N >> M;

    vector<pair<int,int>> road_segments;
    for (int i = 0; i < N; i++) {
        int dist, speed;
        cin >> dist >> speed;
        road_segments.emplace_back(dist, speed);
    }

    vector<pair<int,int>> bessie_segments;
    for (int i = 0; i < M; i++) {
        int dist, speed;
        cin >> dist >> speed;
        bessie_segments.emplace_back(dist, speed);
    }

    size_t road_ptr = 0;
    size_t bessie_ptr = 0;
    int max_speed = 0;
    while (road_ptr < road_segments.size() && bessie_ptr < bessie_segments.size()) {
        max_speed = max(max_speed, bessie_segments[bessie_ptr].second - road_segments[road_ptr].second);
        road_segments[road_ptr].first--;
        bessie_segments[bessie_ptr].first--;
        if (road_segments[road_ptr].first == 0) {
            road_ptr++;
        }
        if (bessie_segments[bessie_ptr].first == 0) {
            bessie_ptr++;
        }
    }

    cout << max_speed << '\n';
    return 0;
}
