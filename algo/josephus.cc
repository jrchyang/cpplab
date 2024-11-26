#include <iostream>
#include <list>

using namespace std;

void josephus(int n, int m)
{
	int result = 0;
	list<int> nums;
	list<int>::iterator cur;

	if (n <= 0 || m <= 0) {
		cout << "invalid nums : " << n << " - " << m << endl;
		return;
	}
	if (n == 1) {
		result = 1;
		goto out;
	}

	for (int i = 0; i < n; ++i) {
		nums.push_back(i);
	}

	cur = nums.begin();
	while (nums.size() > 1) {
		for (int i = 1; i < m; ++i) {
			cur++;
			if (cur == nums.end()) {
				cur = nums.begin();
			}
		}

		cur = nums.erase(cur);
		if (cur == nums.end()) {
			cur = nums.begin();
		}
	}
	result = *cur;

out:
	cout << "the final num is : " << result << endl;
	return;
}

int main()
{
	int n = 0;
	int m = 0;

	cout << "please input total num : ";
	cin >> n;
	cout << "please input count num : ";
	cin >> m;

	josephus(n, m);

	return 0;
}
