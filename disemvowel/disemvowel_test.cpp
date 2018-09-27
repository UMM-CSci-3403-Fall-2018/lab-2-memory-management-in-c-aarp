#include <gtest/gtest.h>

#include "disemvowel.h"

/*
This testing method was built to simplify the testing of simple string comparisons.
 - Takes a pre-calculated char *string pair
 - Call disemvowel on the first
 - ASSERT the strings are equal
 - Smart-clean *result as needed
*/
void test_disemvowel(char *base, char const *expected_result) {
  char *result;
  result = disemvowel(base);
  ASSERT_STREQ(result, expected_result);
  if(result){
    free(result);
  }
}

//Notice how each individual test is now just a call to test_disemvowel
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

//Look how easy it is to make new tests!
TEST(Disemvowel, HandleLiamKoehler) {
  test_disemvowel((char*)"Liam Koehler","Lm Khlr");
}

//Notice that the original tests structure still works as intended.
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
