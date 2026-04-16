#include <cstdlib>
#include <string>
#include "gtest/gtest.h"
#include "formatting.h"
#include "test_helpers.h"
#include "rapidcheck/gtest.h"

auto word_generator() {
    rc::Gen<char> letter = rc::gen::inRange<char>('a', 'z' + 1);
    rc::gen::container<std::string>(letter);
    /* Creates a generator for a string made up of
     * characters from [a - z]
     */
}

auto vector_of_ints_to_vector_of_strings(const std::vector<int>& numbers) {
    /* Create a vector of strings from a vector of ints
     */
    return numbers;
}


TEST(ParseArgsTests, SimpleCheckArgumentsParsedSuccessfully) {
    int argc = 3;
    char arg0[] = "sort_array";
    char arg1[] = "1";
    char arg2[] = "2";
    char* argv[] = {arg0, arg1, arg2};
    int* ar_out = nullptr;
    int* len_out = nullptr;
    parse_args(argc, argv, ar_out, len_out);
    EXPECT_EQ(ar_out[0], 1);
    EXPECT_EQ(ar_out[1], 2);
    EXPECT_EQ(*len_out, 2);
    free(ar_out);

    /*
     * Check that you parse the command line arguments correctly.
     * (ar_out and len_out are set to the right values).
     * Don't forget to free any memory that was dynamically allocated as part of your test.'
     */
}

TEST(ParseArgsTests, SimpleCheckParseNoArgs) {
    int argc = 0;
    char* arg0 = nullptr;
    char** argv = &arg0;
    int* ar_out = nullptr;
    int* len_out = nullptr;
    parse_args(argc, argv, ar_out, len_out);
    EXPECT_EQ(ar_out, nullptr);
    EXPECT_EQ(*len_out, 0);
    /*
     * Check that you parse you can successfully parse "no" command line arguments.
     */
}


RC_GTEST_PROP(ParseArgsTests,
              PropertyCheckArgumentsParsedSuccessfully,
              ()
) {

    /* Check that we can correctly parse the command line
     * arguments when we receive 1 or more arguments.
     * Don't forget to free any memory that was dynamically allocated as part of this test
     */
}

RC_GTEST_PROP(ParseArgsTests,
              PropertyCheckParseNoArgs,
              ()
) {
    /*
     * Check that you parse you can successfully parse "no" command line arguments.
     */
}
