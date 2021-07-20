#include <iostream>

class my_array {
  unsigned size = 0;
  double* data = nullptr;
public:
  my_array() = default;
  my_array(unsigned n) : size(n), data(new double[n]) {
    std::cout << "Constructing: " << data << std::endl;
  }
  my_array(my_array const& other) : size(other.size), data(new double[size]) {
    std::cout << "Copy constructing: " << data << std::endl;
    std::copy(other.data, other.data + size, data);
  }
  my_array& operator=(my_array const& other) {
    std::cout << "Destroying: " <<data << std::endl;
    delete[] data;
    size = other.size;
    data = new double[size];
    std::cout << "Copy assigning: " << data << std::endl;
    std::copy(other.data, other.data + size, data);
    return *this;
  }
  ~my_array() {
    std::cout << "Destroying: " <<data << std::endl;
    delete[] data;
  }
  double& operator[](unsigned i) {
    return data[i];
  }
};

int main() {
  auto null = my_array{};
  auto x = my_array{10};
  auto x_cp = x;
  null = x;
}
