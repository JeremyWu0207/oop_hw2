#include <iostream>
#include <string>

using namespace std;

int main() {
    string S1, S2;
    while (1) {
        cin >> S1 >> S2;
        char ori[100] = {""}; char com[100] = {""}; int i = 0, j = 0;
        if (S1 == "0" && S2 == "0") break;

        for (char c1 : S1) {
            ori[i] = c1;
            i++;
        }
        for (char c2 : S2) {
            com[j] = c2;
            j++;
        }

        int n = 0, m = 0, cnt = 0;
        while (n < i && m < j) {
            if (com[m] == ori[n]) {
                cnt++;
                n++;
            }
            m++;
        }

        if (cnt == i ) cout << "true" << endl;
        else cout << "false" << endl;
    }

    return 0;
}
