#include <iostream>
#include <vector>

template <typename T>
class VectorPrinter {
public:
    static void print(const T& item, std::ostream& os = std::cout) {
        os << item;
    }
};

template <typename T>
class VectorPrinter<std::vector<T>> {
public:
    static void print(const std::vector<T>& vec, std::ostream& os = std::cout) {
        os << "[";
        for (auto it = vec.begin(); it != vec.end(); it++) {
            VectorPrinter<T>::print(*it);
            if (it + 1 != vec.end()) {
                os << ", ";
            }
        }
        os << "]" << std::endl;
    }
};
