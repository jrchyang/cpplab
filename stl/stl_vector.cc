#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v;
	for (int i = 0; i < 10000; ++i) {
		v.push_back(i);
	}
	cout << "Before : size = " << v.size() << ", capa = " << v.capacity() << endl;
	
	v.resize(3);
	cout << "After resize : size = " << v.size() << ", capa = " << v.capacity() << endl;
	vector<int>(v).swap(v);
	cout << "After swap : size = " << v.size() << ", capa = " << v.capacity() << endl;
	v.clear();
	vector<int>(v).swap(v);
	cout << "After swap2 : size = " << v.size() << ", capa = " << v.capacity() << endl;

	return 0;
}
