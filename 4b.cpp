#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main(int argc, char const *argv[])
{
    int d, sumtime;
    cin >> d >> sumtime;
    vector<vector<int>> time(d);
    vector<int> schedule(d);    
    for (int i = 0; i < d; i++) {
        int mintime, maxtime;
        cin >> mintime >> maxtime; 
        time[i] = {mintime, maxtime};
        schedule[i] = mintime;
    }
    int totalspent = accumulate(schedule.begin(), schedule.end(), 0);
    int diff = sumtime - totalspent;
    int maxtotal = 0;
    for (const auto& day : time)
        maxtotal+=day[1];
    if (totalspent > sumtime || maxtotal < sumtime) {
        cout << "NO";
        return 0;
    }
    for (int i = 0; i < d; i++) {
        int left = time[i][1] - schedule[i];
        schedule[i] += min(left, diff);
        diff -= min(left, diff);
    }
    cout << "YES\n";
    for (const auto i : schedule){
        cout << i << " ";
    } 
    return 0;
}
