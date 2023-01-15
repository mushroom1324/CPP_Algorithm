//
// Created by 서찬혁 on 2023/01/15.
//
#include "iostream"
using namespace std;

int main() {
    char num[8];
    cin >> num;
    int count[10] = {0};
    for(int i = 0; num[i]; ++i) {
        count[num[i] - '0'] += 1;
    }
    if ((count[6] + count[9]) % 2) count[6] = (count[6] + count[9]) / 2 + 1;
    else count[6] = (count[6] + count[9]) / 2;
    int max_val = 0;
    for(int i = 0; i < 9; ++i)
        if(max_val < count[i]) max_val = count[i];

    cout << max_val;
}