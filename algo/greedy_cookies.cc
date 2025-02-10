#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int assign_cookies(vector<int>& children, vector<int>& cookies) {
  int child = 0;
  int cookie = 0;

  sort(children.begin(), children.end());
  sort(cookies.begin(), cookies.end());

  while (child < children.size() && cookie < cookies.size()) {
    if (children[child] <= cookies[cookie])
      ++child;
    ++cookie;
  }

  return child;
}

int main() {
  {
    vector<int> children = {2, 1};
    vector<int> cookies = {1, 2, 3};
    cout << assign_cookies(children, cookies) << " children will get cookies" << endl;
  }

  {
    vector<int> children = {5};
    vector<int> cookies = {1, 2, 3};
    cout << assign_cookies(children, cookies) << " children will get cookies" << endl;
  }

  {
    vector<int> children = {5, 6, 1, 4};
    vector<int> cookies = {10, 6, 9, 1};
    cout << assign_cookies(children, cookies) << " children will get cookies" << endl;
  }

  return 0;
}
