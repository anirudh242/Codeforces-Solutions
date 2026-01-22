#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> pages(7);
    for (int i = 0; i < 7; i++) {
        cin >> pages[i];
    }
    int sum = 0;
    int i = 1;
    while (true) {
        sum += pages[i - 1];
        if (sum >= n) {
            cout << i << "\n";
            break;
        }
        i++;
        if (i > 7) i = 1;
    }
    return 0;
}
