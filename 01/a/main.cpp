#include <algorithm>
#include <cmath>
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

  std::sort(std::begin(x), std::end(x));
  std::sort(std::begin(y), std::end(y));

  auto answer{std::transform_reduce(
    std::cbegin(x),
    std::cend(x),
    std::cbegin(y),
    0,
    std::plus<>(),
    [](const auto first, const auto second) { return std::abs(first - second); }
  )};

  std::println("{}", answer);
}
