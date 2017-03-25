#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>

//Only compiles
auto cpp_14() noexcept {
  return "Hello world\n";
}

int sum_a(const std::vector<int>& v)
{
  int sum = 0;
  const auto sz = v.size();
  for (auto i = 0u; i!=sz; ++i)
  {
    sum += v[i];
  }
  return sum;
}

int sum_b(const std::vector<int>& v)
{
  return std::accumulate(
    std::begin(v),
    std::end(v),
    0
  );
}

int main()
{
  #ifndef NDEBUG
  #error Do not profile in debug mode
  #endif
  assert(!"Do not profile in debug mode");
  static_assert("C++17");
  const int sz{100'000'000};
  std::vector<int> v(sz);
  std::iota(std::begin(v), std::end(v), 0);
  for (int i=0; i!=10; ++i)
  {
    const int a{sum_a(v)};
    const int b{sum_b(v)};
    if (a != b) return 1;
  }
  cpp_14();
}
