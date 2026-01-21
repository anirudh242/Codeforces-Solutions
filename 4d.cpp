#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, w, h;
    cin >> n >> w >> h;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    vector<tuple<int,int,int>> valid;
    for (int i = 0; i < n; i++) {
        if (a[i].first > w && a[i].second > h) {
            valid.push_back({a[i].first, a[i].second, i + 1});
        }
    }
    if (valid.empty()) {
        cout << 0 << "\n";
        return 0;
    }
    sort(valid.begin(), valid.end(),
         [](const auto& x, const auto& y) {
             if (get<0>(x) != get<0>(y))
                 return get<0>(x) < get<0>(y);
             return get<1>(x) > get<1>(y);
         });

    int m = valid.size();
    vector<int> dp(m, 1), parent(m, -1);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < i; j++) {
            if (get<1>(valid[j]) < get<1>(valid[i])) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
        }
    }
    int best = 0;
    for (int i = 1; i < m; i++) {
        if (dp[i] > dp[best])
            best = i;
    }
    vector<int> chain;
    for (int cur = best; cur != -1; cur = parent[cur]) {
        chain.push_back(get<2>(valid[cur]));
    }
    reverse(chain.begin(), chain.end());
    cout << chain.size() << "\n";
    for (int x : chain)
        cout << x << " ";
    cout << "\n";
    return 0;
}
