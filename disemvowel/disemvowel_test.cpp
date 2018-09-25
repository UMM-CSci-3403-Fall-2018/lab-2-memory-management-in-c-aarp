#include <gtest/gtest.h>

#include "disemvowel.h"

TEST(Disemvowel, HandleEmptyString) {
  char *stuff;
  stuff = disemvowel((char*) "");
  ASSERT_STREQ("", stuff);
  free(stuff)
}

TEST(Disemvowel, HandleNoVowels) {
  char *stuff;
  stuff = disemvowel((char*) "pqrst");
  ASSERT_STREQ("pqrst", stuff));
  free(stuff)
}

TEST(Disemvowel, HandleOnlyVowels) {
  char *stuff;
  stuff = disemvowel((char*) "aeiouAEIOUOIEAuoiea");
  ASSERT_STREQ("", stuff));
  free(stuff)
}

TEST(Disemvowel, HandleMorrisMinnesota) {
  char *stuff;
  stuff = disemvowel((char*) "Morris, Minnesota");
  ASSERT_STREQ("Mrrs, Mnnst", stuff));
  free(stuff)
}

TEST(Disemvowel, HandlePunctuation) {
  char *stuff;
  stuff = disemvowel((char*) "An (Unexplained) Elephant!");
  ASSERT_STREQ("n (nxplnd) lphnt!", stuff));
  free(stuff)
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
  char *stuff = disemvowel((char*)str);
  ASSERT_STREQ("xyz", stuff);
  free(stuff);
  free(str);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
