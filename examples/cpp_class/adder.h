#pragma once
#include <vector>
#include <cstdint>

static int a = 5;
struct TestData{
  TestData(size_t num = 2048) {}
  std::vector<uint64_t> data;
};
struct FeaRet {
  explicit FeaRet(size_t num = 2048) {
    cat_pos.reserve(num);
    dense_pos.reserve(num);
    cat_vec.reserve(num);
    dense_vec.reserve(64);
  }
  std::vector<std::pair<int, int>> cat_pos;
  std::vector<std::pair<int, int>> dense_pos;
  std::vector<uint64_t> cat_vec;
  std::vector<float> dense_vec;
};
class Adder {
public:
  Adder(int a, int b) : a_(a), b_(b) {}

  int sum() const { return a_ + b_; }
  FeaRet get() {
    auto data = FeaRet();
    data.cat_vec.push_back(1);
    return data;
  }

private:
  int a_;
  int b_;
};
