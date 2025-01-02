#include <algorithm>
#include <fstream>
#include <functional>
#include <numeric>
#include <print>
#include <sstream>
#include <string>
#include <vector>

int main(const int, const char** argv) {
  std::vector<int> x, y;
  std::ifstream file{argv[1]};
  std::string line;
  int i, j;

  while (std::getline(file, line)) {
    std::stringstream ss;
    ss << line;
    ss >> i >> j;
    x.push_back(i);
    y.push_back(j);
  }

  auto answer{std::transform_reduce(
    std::cbegin(x),
    std::cend(x),
    0,
    std::plus<>(),
    [&y](const auto n) { return n * std::count(std::cbegin(y), std::cend(y), n); }
  )};

  std::println("{}", answer);
}
