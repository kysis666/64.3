#include <iostream>

#include <fstream>

#include <string>

using namespace std;

int main() {

    int how = 0, correct = 0, unrec = 0, rec = 0, maxErr = 0, x;
    string photo[21];

    fstream plik;
    plik.open("dane_obrazki.txt", ios:: in );

    while (!plik.eof()) {

        int wRow = 0, wCol = 0, errCol = 0, errRow = 0;

        for (int i = 0; i < 21; i++) {
            plik >> photo[i];

        }

        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                if (photo[i][j] == '1') {
                    how++;
                }
                if (j == 19) {
                    if (how % 2 == 1) {
                        x = '1';
                    } else {
                        x = '0';
                    }
                    if (x != photo[i][20]) {
                        wRow++;
                    }
                    how = 0;
                }
            }
        }

        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                if (photo[j][i] == '1') {
                    how++;
                }
                if (j == 19) {
                    if (how % 2 == 1) {
                        x = '1';
                    } else {
                        x = '0';
                    }
                    if (photo[20][i] != x) {
                        wCol++;
                    }
                    how = 0;
                }
            }
        }

        if (wCol > 1 || wRow > 1) {
            unrec++;
        } else if (wCol > 0 || wRow > 0) {
            rec++;
        } else if (wCol == 0 || wRow == 0) {
            correct++;
        }

        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                if (photo[i][j] == '1') {
                    how++;
                }
                if (j == 19) {
                    if (how % 2 == 1) {
                        x = '1';
                    } else {
                        x = '0';
                    }
                    if (x != photo[i][20]) {
                        errRow++;
                    }
                    how = 0;
                }
            }
        }

        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                if (photo[j][i] == '1') {
                    how++;
                }
                if (j == 19) {
                    if (how % 2 == 1) {
                        x = '1';
                    } else {
                        x = '0';
                    }
                    if (photo[20][i] != x) {
                        errCol++;
                    }
                    how = 0;
                }
            }
        }
        if (maxErr < errCol + errRow) {
            maxErr = errCol + errRow;
        }

    }
    cout << correct << endl;
    cout << unrec << endl;
    cout << rec << endl;
    cout << maxErr;

    return 0;
}
