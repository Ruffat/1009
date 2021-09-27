#include <iostream>
#define k 10001
using namespace std;
int main() {
    char S1[k];
    S1[0] = 0;
    cin >> S1;
    int dlina = strlen(S1);
    if(dlina !=1){
        for (int i = 1; i < dlina; i++) {
            bool tmp = true;
            int length = dlina - i;
            for (int j = 0; j < length; j++) {
                if (tmp) {
                    if (S1[i + j] != S1[dlina - j - 1]) {
                        tmp = false;
                    }
                }
            }
            if (tmp) {
                cout << S1;
                for (int j = i - 1; j >= 0; j--) {
                    cout << S1[j];
                }
                cout << endl;
                break;
            }
        }
    }
    else {
        cout << S1;
        cout << S1;
    }
    return 0;
}
