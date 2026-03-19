#include <iostream>
#include <vector>
using namespace std;

int change_coin(vector<int> &coin, int m) {
    vector<long> dp(m+1, 0);
    dp[0] = 1;
    
    for (auto &c : coin) {
        for (int i = c; i < m;i++) {
            dp[i] += dp[i - c];
        }
    }
    return dp[m];
}


int main() {
    vector<int> coin = {1, 5,10, 50};
    while (1) {
        int money;
        cin >> money;
        if (money == 0) break;
        cout << change_coin(coin, money) << endl;;
    }
    
    return 0;
}
