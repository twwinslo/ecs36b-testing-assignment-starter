#include <cstdlib>
#include <vector>
#include <algorithm>
#include "test_helpers.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "sorting.h"
#include "rapidcheck/gtest.h"


TEST(SwapTests, SimpleSwapTwoValues) {
    int a = 1;
    int b = 2;
    swap(&a, &b);
    EXPECT_EQ(a,2);
    EXPECT_EQ(b,1);
    /*
     * Swap two values and see if the swap was successful.
     */
}

TEST(SwapTests, SimpleSwapValuesInArray) {
    int arr[] = {1,2,3,4,5};
    swap(&arr[1], &arr[2]);
    swap(&arr[2],&arr[3]);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 3);
    EXPECT_EQ(arr[2], 4);
    EXPECT_EQ(arr[3], 2);
    EXPECT_EQ(arr[4], 5);

    /*
     * Swap a few values in an array.
     * Check that the ones that swapped did swap and the ones that didn't swap
     * are still at the same locations
     */
}

RC_GTEST_PROP(SwapTests,
              PropertySwapTwoValues,
              (int a_start, int b_start)
) {
    int a = a_start;
    int b = b_start;
    swap(&a, &b);
    EXPECT_EQ(a_start, b);
    EXPECT_EQ(b_start, a);
    /*
     * Swap two values and see if the swap was successful.
     */
}


RC_GTEST_PROP(SwapTests,
              PropertySwapValuesInArray,
              (const std::vector<int>& values)
) {
    int arr[values.size()];
    copy_vector_to_array(values, arr);
    swap(&arr[0], &arr[1]);
    long unsigned int i = 0;
    EXPECT_EQ(arr[0], arr[1]);
    i++;
    EXPECT_EQ(arr[1], arr[0]);
    i++;
    for (; i <= values.size(); i++) {
        EXPECT_EQ(arr[i], arr[i]);
    }

    /*
     * Swap two values in an array. See that they swapped and the others did not
     */
}
