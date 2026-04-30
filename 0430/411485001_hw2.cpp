#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> Vincent;
    vector<string> Leo;
    vector<string> Invitee;
    string name;

    // 讀取 Vincent 的朋友
    cout << "#Vincent's friend:\n";
    while (cin >> name && name != "0") {
        Vincent.push_back(name);
    }

    // 讀取 Leo 的朋友
    cout << "\n#Leo's friend:\n";
    while (cin >> name && name != "0") {
        Leo.push_back(name);
    }

    // 合併並過濾重複者放入 Invitee
    // 1. 先處理 Vincent 的名單
    for (int i = 0; i < Vincent.size(); i++) {
        bool isDuplicate = false;
        for (int j = 0; j < Invitee.size(); j++) {
            if (Vincent[i] == Invitee[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            Invitee.push_back(Vincent[i]);
        }
    }

    // 2. 接著處理 Leo 的名單，與目前 Invitee 比對
    for (int i = 0; i < Leo.size(); i++) {
        bool isDuplicate = false;
        for (int j = 0; j < Invitee.size(); j++) {
            if (Leo[i] == Invitee[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            Invitee.push_back(Leo[i]);
        }
    }

    // 輸出最終邀請名單
    cout << "\n#Invitee:\n";
    for (int i = 0; i < Invitee.size(); i++) {
        cout << Invitee[i] << "\n";
    }

    return 0;
}
