#include <iostream>
#include <vector>

using namespace std;

// 模擬單次 m 值下的斷電過程
bool simulatePowerOutage(int N, int m) {
    vector<int> regions;
    for (int i = 1; i <= N; ++i) {
        regions.push_back(i);
    }

    // 奧克蘭（區域 1）首先被斷開，索引為 0
    int currentIndex = 0;
    regions.erase(regions.begin() + currentIndex);

    // 依序移除間距 m 的區域
    while (regions.size() > 1) {
        currentIndex = (currentIndex + m - 1) % regions.size();
        regions.erase(regions.begin() + currentIndex);
    }

    // 驗證最後剩下的區域是否為威靈頓（區域 13）
    return regions.front() == 13;
}

// 尋找符合條件的最小 m 值
int findMinimalM(int N) {
    // 依據限制條件進行基礎過濾
    if (N < 13 || N >= 100) return -1;
    
    int m = 1;
    while (true) {
        if (simulatePowerOutage(N, m)) {
            return m;
        }
        m++;
        
        // 設置防護機制，避免如 N=14 等無解情況導致無窮迴圈
        if (m > 10000) {
            return -1; 
        }
    }
}
