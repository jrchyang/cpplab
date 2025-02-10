#include <iostream>
#include <vector>

using namespace std;

bool can_place_flowers(vector<int>& flowerbed, int n) {
    int i = 0;
    int prev = -1;
    int total = 0;
    int size = flowerbed.size();

    if (size == 1) {
        return (flowerbed[0] == 0 ? 1 : 0) >= n;
    }

    for (i = 0; i < flowerbed.size(); ++i) {
        if (flowerbed[i] == 0) {
            continue;
        }

        if (prev == -1) {
            total += i < 2 ? 0 : (i / 2);
        } else {
            int cnt = i - prev - 1;
            total += cnt <= 2 ? 0 : ((cnt - 1) / 2);
        }

        prev = i;
    }

    if (prev != size - 1) {
        if (prev == -1) {
            total += (i + 1) / 2;
        } else {
            int cnt = i - prev - 1;
            total += cnt < 2 ? 0 : (cnt / 2);
        }
    }

    return total >= n;
}
