#include <gtest/gtest.h>

#include "disemvowel.h"

void test_disemvowel(char *base, char const *expected_result) {
  char *result;
  result = disemvowel(base);
  ASSERT_STREQ(result, expected_result);
  if(result){
    free(result);
  }
}

TEST(Disemvowel, HandleEmptyString) {
  test_disemvowel((char*)"","");
}

TEST(Disemvowel, HandleNoVowels) {
  test_disemvowel((char*)"pqrst","pqrst");
}

TEST(Disemvowel, HandleOnlyVowels) {
  test_disemvowel((char*)"aeiouAEIOUOIEAuoiea","");
}

TEST(Disemvowel, HandleMorrisMinnesota) {
  test_disemvowel((char*)"Morris, Minnesota","Mrrs, Mnnst");
}

TEST(Disemvowel, HandlePunctuation) {
  test_disemvowel((char*)"An (Unexplained) Elephant!","n (nxplnd) lphnt!");
}

TEST(Disemvowel, HandleLongString) {
  char *str;
  int size;
  int i;

  size = 50000;
  str = (char*) calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';

  char *result = disemvowel((char*)str);
  ASSERT_STREQ("xyz", result);
  free(result);
  free(str);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
