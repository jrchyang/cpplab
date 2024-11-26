#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void display(int x)
{
	cout << " " << x;
	return;
}

int main()
{
	vector<int> v;
	int x;
	cin >> x;
	while (x > 0) {
		v.push_back(x);
		cin >> x;
	}

	cout << "Max = " << *max_element(v.begin(), v.end()) << endl;
	cout << "Sum = " << accumulate(v.begin(), v.end(), 0) << endl;
	sort(v.begin(), v.end());
	cout << "Sorted result is : \n";
	for_each(v.begin(), v.end(), display);
	cout << '\n';

	return 0;
}
