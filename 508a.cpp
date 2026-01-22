#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0 ; i < n; i++) {
        cin >> a[i];
    } 
    int currsub = 1;
    int maxsub = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] >= a[i-1]) currsub++;
        else currsub = 1;
        maxsub = max(currsub, maxsub);
    }
    cout << maxsub << "\n";
    return 0;
}
