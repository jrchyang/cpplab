#include <iostream>
#include <vector>

using namespace std;

bool can_place_flowers(vector<int>& flowerbed, int n) {
    int size = flowerbed.size();
    int prev = -1;
    int total = 0;

    for (int i = 0; i < size; ++i) {
        if (flowerbed[i] == 1) {
            if (prev == -1) {
                total += i / 2;
            } else {
                total += (i - prev - 2) / 2;
            }

            prev = i;
        }
    }

    if (prev == -1) {
        total += (size + 1) / 2;
    } else {
        total += (size - prev - 1) / 2;
    }

    return total >= n;
}

int main() {
    {
        vector<int> flowerbed = {1, 0, 0, 0, 1};
        int n = 1;
        cout << "result is " << (can_place_flowers(flowerbed, n) == true ? "true" : "false") << endl;
    }
    {
        vector<int> flowerbed = {1, 0, 0, 0, 1};
        int n = 2;
        cout << "result is " << (can_place_flowers(flowerbed, n) == true ? "true" : "false") << endl;
    }
    {
        vector<int> flowerbed = {0, 0, 0};
        int n = 2;
        cout << "result is " << (can_place_flowers(flowerbed, n) == true ? "true" : "false") << endl;
    }
    {
        vector<int> flowerbed = {1, 0, 1, 0, 0};
        int n = 1;
        cout << "result is " << (can_place_flowers(flowerbed, n) == true ? "true" : "false") << endl;
    }
    {
        vector<int> flowerbed = {1, 0, 1, 0, 0};
        int n = 2;
        cout << "result is " << (can_place_flowers(flowerbed, n) == true ? "true" : "false") << endl;
    }

    return 0;
}
