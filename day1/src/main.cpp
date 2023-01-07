#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <ranges>
#include <string>
#include <utility>
#include <vector>

void part1(const std::vector<std::string> &input) {
  auto calories_by_elf =
      input | std::views::lazy_split("") |
      std::views::transform([](const auto &in) -> int {
        auto to_int = [](const auto &s) { return std::stoi(s); };
        auto by_elf = in | std::views::transform(to_int) | std::views::common;

        return std::reduce(by_elf.begin(), by_elf.end());
      });
  auto it = std::ranges::max_element(calories_by_elf);

  std::cout << *it << std::endl;
}

void part2(const std::vector<std::string> &input) {
  auto calories_by_elf =
      input | std::views::lazy_split("") |
      std::views::transform([](const auto &in) -> int {
        auto to_int = [](const auto &s) { return std::stoi(s); };
        auto by_elf = in | std::views::transform(to_int) | std::views::common;

        return std::reduce(by_elf.begin(), by_elf.end());
      });
  std::vector<int> result(3);
  std::ranges::partial_sort_copy(calories_by_elf, result, std::greater<>());
  auto sum = std::reduce(result.begin(), result.end());
  std::cout << "part2 result: " << sum << std::endl;
}

int main() {
  std::vector<std::string> lines;
  std::string line;
  std::ifstream file("../input.txt");
  if (file.is_open()) {
    while (std::getline(file, line)) {
      lines.push_back(std::move(line));
    }
    file.close();
  } else {
    std::cout << "file could not be opened" << std::endl;
  }

  part1(lines);
  part2(lines);

  return 0;
}
