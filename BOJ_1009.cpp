//
// Created by 서찬혁 on 2023/01/13.
//
#include <iostream>
using namespace std;
int main() {
    int T;
    cin >> T;
    for(int i = 0; i < T; ++i) {
        int a, b, ans = 1;
        cin >> a >> b;
        for(int j = 0; j < b; ++j) {
            ans = ans * a % 10;
        }
        if(ans == 0) ans = 10;
        cout << ans << endl;
    }
}
