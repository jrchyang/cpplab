#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct MyLower {
	int operator ()(int x) const {
		return tolower(x);
	}
};

struct MyUpper {
	int operator ()(int x) const {
		return toupper(x);
	}
};

int main()
{
	string str = "Hello World";

	transform(str.begin(), str.end(), str.begin(), MyLower());
	cout << str << endl;
	transform(str.begin(), str.end(), str.begin(), MyUpper());
	cout << str << endl;

	int val = 666;
	cout << to_string(val) << endl;


	return 0;
}
