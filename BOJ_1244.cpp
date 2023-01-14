//
// Created by 서찬혁 on 2023/01/14.
//
#include <iostream>
using namespace std;

int main() {
    int T;
    int num_of_st;

    cin >> T;
    if (!T) {
        return 0;
    }
    bool arr[T];

    for(int i = 0; i < T; ++i) {
        cin >> arr[i];
    }
    cin >> num_of_st;

    for(int i = 0; i < num_of_st; ++i) {
        int gender, num;
        cin >> gender >> num;
        if (gender == 1) {
            int temp = num;
            int temp2 = 2;
            while(temp <= T) {
                arr[temp-1] = !arr[temp-1];
                temp = num * temp2++;
            }
        } else {
            int temp = 1;
            while(num-1 - temp >= 0 && num-1 + temp < T && arr[num-1 - temp] == arr[num-1 + temp]) {
                temp += 1;
            }
            arr[num-1] = !arr[num-1];
            for(int i = 1; i < temp; ++i) {
                arr[num-1 + i] = !arr[num-1 + i];
                arr[num-1 - i] = !arr[num-1 - i];
            }
        }
    }
    int i;
    for(i = 0; i < T-1; ++i) {
        cout << arr[i] << " ";
        if (i && !((i+1) % 20) ) cout << endl;
    }
    cout << arr[i];
}

