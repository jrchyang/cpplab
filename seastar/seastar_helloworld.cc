#include <seastar/core/app-template.hh>
#include <seastar/core/reactor.hh>
#include <seastar/core/sleep.hh>
#include <seastar/util/log.hh>
#include <iostream>
#include <stdexcept>

seastar::future<int> slow() {
	using namespace std::chrono_literals;
	return seastar::sleep(100ms).then([] { return 3; });
}

seastar::future<int> fast() {
	return seastar::make_ready_future<int>(3);
}

/*
seastar::future<> f() {
	return slow().then([] (int val) {
		std::cout << "Got " << val << "\n";
	});
}
*/

seastar::future<> f() {
	return fast().then([] (int val) {
		std::cout << "Got " << val << "\n";
	});
}

int main(int argc, char** argv) {
	seastar::app_template app;
	try {
		app.run(argc, argv, f);
	} catch(...) {
		std::cerr << "Couldn't start application: "
			<< std::current_exception() << "\n";
		return 1;
	}
	return 0;
}
