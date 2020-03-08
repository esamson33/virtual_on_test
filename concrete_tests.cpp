#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "concrete.h"

class mock_a : public a
{
public:
  MOCK_METHOD(void, do_something, ());
};

TEST(AlphabetTest, test_a) {
  mock_a an_a;
  EXPECT_CALL(an_a, do_something()).Times(1);

  an_a.something();
}

int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
