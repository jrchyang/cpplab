#include <iostream>
#include <vector>
#include <algorithm>

void process_vector(const std::vector<int>& vec, const std::function<void(int)>& func)
{
	for (int n : vec) {
		func(n);
	}
}

int main(int argc, char **argv)
{
	// 使用 lambda 排序与回调
	std::vector<int> nums = {5, 2, 8, 1, 3};
	std::sort(nums.begin(), nums.end(), [](int a, int b) {
		return a < b;
	});
	process_vector(nums, [](int n){
		std::cout << n << std::endl;
	});

	// 捕获外部变量
	int x = 10;
	auto l1 = [x]() {
		std::cout << "in lambda 1 x = " << x << std::endl;
	};
	auto l2 = [&x]() {
		x += 5;
		std::cout << "in lambda 2 x = " << x << std::endl;
	};

	l1();
	l2();
	std::cout << "in main x = " << x << std::endl;
	l1();
	l2();

	return 0;
}
