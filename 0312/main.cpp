#include <iostream>
#include <string>
#include "skin.h"

using namespace std;

void displayShop(skin skins[], int size) {
    cout << "\n=================== Skin Shop ===================\n\n";

    string currentChar = "";
    for (int i = 0; i < size; i++) {
        if (skins[i].getCharacterName() != currentChar) {
            if (i != 0) cout << "\n";

            currentChar = skins[i].getCharacterName();
            cout << currentChar << ":\n  ";
        }
        cout << skins[i].getSkinName() << ": ";
        if (skins[i].getIsSold()) {
            cout << "Sold Out  ";
        } else {
            cout << skins[i].getPrice() << "  ";
        }
    }
    cout << "\n\n=================================================\n\n";
}

int main() {
    skin shop[6] = {
        skin("C1", "S1", 100),
        skin("C1", "S2", 200),
        skin("C1", "S3", 300),
        skin("C2", "S4", 400),
        skin("C2", "S5", 700),
        skin("C2", "S6", 800)
    };

    int accountBalance;
    cout << "Enter the account amount: ";
    cin >> accountBalance;

    int choice;
    while (true) {
        cout << "Enter 1 to buy a skin, 2 to exit: ";
        cin >> choice;

        if (choice == 2) {
            cout << "\nThanks for coming. Hope to see you again soon!\n";
            break;
        } else if (choice == 1) {
            displayShop(shop, 6);
            cout << "Account balance: " << accountBalance << "\n\n";

            string targetChar, targetSkin;
            cout << "Enter the character you want to choose: ";
            cin >> targetChar;
            cout << "Enter the skin you want to purchase: ";
            cin >> targetSkin;

            for (int i = 0; i < 6; i++) {
                if (shop[i].getCharacterName() == targetChar && shop[i].getSkinName() == targetSkin) {
                    if (shop[i].getIsSold()) {
                        cout << "Sold out!\n\n";
                    }
                    else if (accountBalance >= shop[i].getPrice()) {
                        accountBalance -= shop[i].getPrice();
                        shop[i].setIsSold(true);

                        cout << "\nCongratulation! You have skin \"" << targetSkin << "\" now.\n";
                        cout << "Account balance: " << accountBalance << "\n\n";
                    }
                    else {
                        cout << "Sorry! Insufficient account balance.\n\n";
                    }
                    break;
                }
            }
        }
    }
    return 0;
}
