#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int n, q; cin >> n >> q;
    vector<long long > prices(n);
    for(int i=0; i<n; i++) cin >> prices[i];
    sort(prices.begin(), prices.end());
    vector<long long> maxPrice(n+1); maxPrice[0] = 0;
    for(int i=0; i<n; i++) {
        if(i == 0) maxPrice[i+1] = prices[i]*(100-q)/100;
        else if(i == 1) maxPrice[i+1] = maxPrice[i] + prices[i]*(100-q)/100;
        else maxPrice[i+1] = min(maxPrice[i] + prices[i]*(100-q)/100, maxPrice[i-2] + prices[i] + prices[i-1]);
    }
    cout << maxPrice[n];
    return 0;
}

