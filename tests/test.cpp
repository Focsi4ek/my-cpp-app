#include <gtest/gtest.h>

#include <string>

std::string getGreeting() {
  return "Hello from C++ in Docker! 🐳";
}

TEST(GreetingTest, ReturnsCorrectString) {
  EXPECT_EQ(getGreeting(), "Hello from C++ in Docker! 🐳");
}

TEST(GreetingTest, ContainsKeywords) {
  std::string greeting = getGreeting();

  EXPECT_TRUE(greeting.find("C++") != std::string::npos);
  EXPECT_TRUE(greeting.find("Docker") != std::string::npos);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
