#include <iostream>
#include <string>

std::string getGreeting() { return "Hello from C++ in Docker! 🐳"; }

int main() {
  std::cout << getGreeting() << std::endl;
  return 0;
}
