#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    ifstream ifs("rental.in"); ofstream ofs("rental.out");
    int n, m, r; ifs >> n >> m >> r;
    vector<int> rent(r); vector<int> numMilk(n); vector<pair<int, int> > buy(m);
    for(int i=0; i<n; i++) ifs >> numMilk[i];
    for(int i=0; i<m; i++) ifs >> buy[i].second >> buy[i].first;
    for(int i=0; i<r; i++) ifs >> rent[i];

    sort(numMilk.begin(), numMilk.end(), greater<int>()); sort(rent.begin(), rent.end()); sort(buy.begin(), buy.end());

    vector<long long> bought;
    int j = m-1; long long sum = 0;
    for(int i=0; i<n; i++) {
        while(j > -1){
            if(numMilk[i] <= buy[j].second) {
                sum += (numMilk[i]*buy[j].first);
                buy[j].second -= numMilk[i];
                break;
            } else {
                sum += (buy[j].first*buy[j].second);
                numMilk[i] -= buy[j].second;
                buy[j].second = 0;
                j--;
            }
        }
        bought.push_back(sum);
    }

    long long ans = 0; sum = 0;
    for(int i=0; i<=min(n, r); i++) {
        sum += rent[r-i];
        long long cur = sum + bought[n-i-1];
        ans = max(ans, cur);
    }
    ofs << ans;
    return 0;
}

