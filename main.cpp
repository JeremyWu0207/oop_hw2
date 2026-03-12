#include <bits/stdc++.h>
#include "skin.h"

using namespace std;

void display() {
    cout << "================= skin shop =================" << endl;
    cout << "C1:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << shop[i].getsname();
        if (shop[i].getsname().is_sold == 1) {
            cout << "Sold out    ";
        }
        else {
            cout << shop[i].getsname().getprice() << "    ";
        }
    }
    cout << "C2:" << endl;
    for (int i = 3; i < 6; i++) {
        cout << shop[i].getsname();
        if (shop[i].getsname().is_sold == 1) {
            cout << "Sold Out    ";
        }
        else {
            cout << shop[i].getsname().getprice() << "    ";
        }
    }
    cout << "=========================================" <<endl;
}

int main() {
    skin shop[6] = {
        Skin("C1", "S1",100),
        Skin("C1", "S2",200),
        Skin("C1", "S3",300),
        Skin("C2", "S4",400),
        Skin("C2", "S5",700),
        Skin("C2", "S6",800);
    }

        display();
    int purchase_willing = 0, balance = 0;
    cin >> "Enter the account amount: " >> amount >> endl;
    while (1) {
        cin >> "Enter 1 to buy a skin, 2 to exit: " >> purchase_willing >> endl;
        if (purchase_willing == 2) break;

        cout << "Account balance: " << balance;
        cin >> "Enter the character you want to choose: " << #cn << endl;
        cin >> "Enter the skin you want to purchase: " << #sn << endl;
        if (s.get_is_sold == 1) cout << "Sold out!";
        if (balance < s.getprice()) cout << "Sorry!";

    }




}
