#include <print>
#include <vector>

int main() {
    std::vector<int> v{1, 2, 3, 4};
    for (auto x : v) {
        std::println("x = {}", x);
    }
}
