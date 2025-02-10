#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int candies(vector<int>& scores) {
    int size = scores.size();
    if (size < 2)
        return size;

    vector<int> candies(size, 1);

    for (int i = 1; i < size; ++i) {
        if (scores[i] > scores[i-1])
            candies[i] = candies[i-1] + 1;
    }

    for (int i = size - 1; i > 0; --i) {
        if (scores[i-1] > scores[i] && candies[i-1] <= candies[i])
            candies[i-1] = candies[i] + 1;
    }

    return accumulate(candies.begin(), candies.end(), 0);
}

int main() {
    {
        vector<int> scores = {1, 0, 2};
        cout << "need " << candies(scores) << " candies for all" << endl;
    }

    return 0;
}
