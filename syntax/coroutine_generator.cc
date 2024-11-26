#include <iostream>
#include <thread>
#include <coroutine>
#include <functional>

struct Generator {
	struct promise_type {
		std::suspend_always initial_suspend() { return {}; }
		std::suspend_always final_suspend() noexcept { return {}; }
		void unhandled_exception() {}
		Generator get_return_object() {
			return Generator{ std::coroutine_handle<promise_type>::from_promise(*this) };
		}
		void return_void() {}

		std::suspend_always await_transform(int value) {
			this->value = value;
			return {};
		}

		int value;
	};

	int next() {
		handle.resume();
		return handle.promise().value;
	}

	std::coroutine_handle<promise_type> handle;
};

Generator sequence() {
	int i = 0;

	while (true) {
		co_await i++;
	}
}

int main()
{
	auto gen = sequence();

	for (int i = 0; i < 5; ++i) {
		std::cout << gen.next() << std::endl;
	}

	return 0;
}
