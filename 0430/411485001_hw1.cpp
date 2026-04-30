#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int h, m;
    
    // 持續輸入，若讀取到 -1 則結束程式
    while (cin >> h) {
        if (h == -1) {
            break;
        }
        cin >> m;

        // 計算時針角度 (0-360度)
        // 12小時制，每小時 30 度；每分鐘時針會移動 0.5 度
        double hour_angle = (h % 12) * 30.0 + (m * 0.5);

        // 計算分針角度 (0-360度)
        // 每分鐘分針移動 6 度
        double minute_angle = m * 6.0;

        // 取得兩針夾角的絕對值
        double diff = abs(hour_angle - minute_angle);

        // 確保為最小正角度 (不超過 180 度)
        if (diff > 180.0) {
            diff = 360.0 - diff;
        }

        // 四捨五入並轉為整數輸出，避免印出小數點
        cout << (int)round(diff) << "\n";
    }

    return 0;
}
