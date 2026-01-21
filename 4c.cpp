#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    unordered_map<string, int> seen;
    while (n--) {
        string name;
        cin >> name;
        if (seen[name] == 0) {
            cout << "OK\n";
        } else {
            cout << name << seen[name] << "\n";
        }
        seen[name]++;
    }
    return 0; 
}
