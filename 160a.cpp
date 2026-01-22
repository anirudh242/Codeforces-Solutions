#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end());
    int totalsum = accumulate(coins.begin(), coins.end(), 0);
    int mysum = 0;
    int needed = 0;
    for (int i = coins.size() -1; i >= 0;i--) {
        mysum += coins[i];
        needed++;
        if (mysum > totalsum - mysum) break;
    }
    cout << needed << "\n";
}
