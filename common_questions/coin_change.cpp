#include<iostream>
#include<vector>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    int Max = amount + 1;
    vector<int> calculated(amount + 1, Max);
    calculated[0] = 0;
    for (int i = 1; i <= amount; i++) {
        for (auto& x : coins) {
            if (i >= x) calculated[i] = min(calculated[i], calculated[i - x] + 1);
        }
    }
    return (calculated[amount] == Max ? -1 : calculated[amount]);
}

int main() {
    int amount, n; cin >> amount >> n;
    vector<int> coins(n);
    for(int i=0; i<n; i++) cin >> coins[i];
    cout << coinChange(coins, amount);
    return 0;
}

