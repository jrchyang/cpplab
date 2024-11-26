#include <iostream>
#include <thread>
#include <coroutine>
#include <functional>

using call_back = std::function<void(int)>;

void addByCallback(int init, call_back f) {
	std::thread t([init, f]() {
		std::this_thread::sleep_for(std::chrono::seconds(5));
		f(init + 100);
	});
	t.detach();
}

struct Task {
	struct promise_type {
		auto get_return_object() {
			return Task{};
		}

		auto initial_suspend() {
			return std::suspend_never{};
		}

		auto final_suspend() noexcept {
			return std::suspend_never{};
		}

		void unhandled_exception() {
			std::terminate();
		}

		void return_void() {}
	};
};

struct addByWaitable {
	addByWaitable(int init) : init_(init) {
	}
	bool await_ready() const { return false; }
	int await_resume() { return result_; }
	void await_suspend(std::coroutine_handle<> handle) {
		auto f = [handle, this](int value) mutable {
			result_ = value;
			handle.resume();
		};
		addByCallback(init_, f);
	}
	int init_;
	int result_;
};

Task addByCoroutine(int init, call_back f) {
	int ref = co_await addByWaitable(init);
	ref = co_await addByWaitable(ref);
	ref = co_await addByWaitable(ref);

	f(ref);
}

int main(int argc, char **argv)
{
	addByCoroutine(5, [](int value){
		std::cout << "get result from coroutine: " << value << std::endl;
	});

	std::cout << "waiting for addByCoroutine end ..." << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(20));

	return 0;
}
