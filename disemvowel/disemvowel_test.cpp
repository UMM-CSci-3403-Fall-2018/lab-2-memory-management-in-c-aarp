#include <gtest/gtest.h>

#include "disemvowel.h"

void test_disemvowel(char const *base, char const *expected_result) {
  char *result;
  result = disemvowel(base)
  ASSERT_STREQ(result, expected_result);
  if(strlen(result) >= 0){
    free(result);
  }
}

// TEST(Disemvowel, HandleEmptyString) {
//   char *result = disemvowel((char*) "");
//   ASSERT_STREQ("", result);
//   free(result);
// }

TEST(Disemvowel, HandleNoVowels) {
  test_disemvowel("pqrst","pqrst");
}

TEST(Disemvowel, HandleOnlyVowels) {
  char *result = disemvowel((char*) "aeiouAEIOUOIEAuoiea");
  ASSERT_STREQ("", result);
  free(result);
}

TEST(Disemvowel, HandleMorrisMinnesota) {
  char *result = disemvowel((char*)"Morris, Minnesota");
  ASSERT_STREQ("Mrrs, Mnnst", result);
  free(result);
}

TEST(Disemvowel, HandlePunctuation) {
  char *result = disemvowel((char*)"An (Unexplained) Elephant!");
  ASSERT_STREQ("n (nxplnd) lphnt!", result);
  free(result);
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
