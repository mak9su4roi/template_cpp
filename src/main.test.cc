#include <gtest/gtest.h>
#include "options_parser/options_parser.h"

// Demonstrate some basic assertions.
TEST(FlagPresent, BasicAssertions) {
  // Expect two strings not to be equal.
  int argcxx = 2;
  char* argvxx[] = {"main.test.cxx", "-A", NULL};
  EXPECT_TRUE(command_line_options_t(argcxx, argvxx).get_A_flag());
}

TEST(FlagAbsent, BasicAssertions) {
  // Expect two strings not to be equal.
  int argcxx = 2;
  char* argvxx[] = {"main.test.cxx", "-X", NULL};
  EXPECT_FALSE(command_line_options_t(argcxx, argvxx).get_A_flag());
}