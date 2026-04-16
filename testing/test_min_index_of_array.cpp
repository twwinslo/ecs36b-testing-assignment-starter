#include <vector>
#include <algorithm>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "rapidcheck/gtest.h"
#include "sorting.h"
#include "test_helpers.h"

TEST(MinIndexOfArrayTests, SimpleMinIndexAtFrontOfArray) {
    int arr[] = {1,2,3,4,5};
    int min_index = min_index_of_array(arr, 5);
    ASSERT_EQ(min_index, 0);
    /*
     * See if we can find the index of the minimum value when it is at the front of the array
     */
}

TEST(MinIndexOfArrayTests, SimpleMinIndexAtEndOfArray) {
    int arr[] = {5,4,3,2,1};
    int min_index = min_index_of_array(arr, 5);
    ASSERT_EQ(min_index, 4);
    /*
     * See if we can find the index of the minimum value when it is at the end of the array
     */
}

TEST(MinIndexOfArrayTests, SimpleMinIndexAtMiddleOfArray) {
    int arr[] = {5,4,3,4,5};
    int min_index = min_index_of_array(arr, 5);
    ASSERT_EQ(min_index, 2);
    /*
     * See if we can find the index of the minimum value when it is somewhere
     * in the "middle" of the array.
     */
}

TEST(MinIndexOfArrayTests, SimpleDuplicateMinimums) {
    int arr[] = {1,2,3,4,1};
    int min_index = min_index_of_array(arr, 5);
    ASSERT_EQ(min_index, 0);
    /*
     * See if we return the index of the first minimum in the array
     * When there are multiple values that are the minimum.
     */
}

TEST(MinIndexOfArrayTests, SimpleArrayDoesNotChange) {
    int arr[] = {1,2,3,4,5};
    min_index_of_array(arr, 5);
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(arr[i], i+1);
    }
    /*
     * Check that finding the minimum of the array did not change the contents of the array.
     */
}


RC_GTEST_PROP(MinIndexOfArrayTests,
              PropertyFindMinIndex,
              (const std::vector<int>&values)) {
    int arr[values.size()];
    copy_vector_to_array(values, arr);
    int min_index = min_index_of_array(arr, values.size());
    for (long unsigned int i = 0; i < values.size(); i++) {
        EXPECT_GE(arr[i], arr[min_index]);
    }
    /* Check that the value at the location of the minimum index
     * is not larger than any of the other values in the array
     */
}

RC_GTEST_PROP(MinIndexOfArrayTests,
              PropertyArrayDoesNotChange,
              (const std::vector<int>&values)) {
    int arr[values.size()];
    copy_vector_to_array(values, arr);
    min_index_of_array(arr, values.size());
    for (long unsigned int i = 0; i < values.size(); i++) {
        EXPECT_EQ(arr[i], values[i]);
    }
    /*
     * Check that finding the minimum of the array did not change the contents of the array.
     */
}
