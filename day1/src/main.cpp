#include <iostream>
#include<ranges>
#include<string>
#include<utility>
#include<fstream>
#include<vector>
#include<algorithm>
#include <numeric>


void part1(const std::vector<std::string> &input){
  auto calories_by_elf = input | std::views::lazy_split("") 
    | std::views::transform([](const auto &in) -> int {
        auto to_int = [](auto s){return std::stoi(s);};
        auto by_elf = in | std::views::transform(to_int) |
        std::views::common;
    
    return std::reduce(by_elf.begin(), by_elf.end());

    });
    auto it = std::ranges::max_element(calories_by_elf);

   std::cout<<*it<<std::endl;

}

void part2(const std::vector<std::string> &input){
  // auto calories_by_elf = input | std::views::lazy_split("") 
  //   | std::views::transform([](auto in) -> int {
  //       auto to_int = [](auto s){return std::stoi(s);};
  //       auto by_elf = in | std::views::transform(to_int);
    
  //   return std::reduce(by_elf.begin(), by_elf.end(), std::greater());

  //   });
  // std::cout<<std::ranges::max_element(calories_by_elf)<<std::endl;

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
        std::cout<< "file could not be opened"<<std::endl;
    }

    part1(lines);

    return 0;
}
        
