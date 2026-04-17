#include <cstdlib>
#include <vector>
#include "gtest/gtest.h"
#include "sorting.h"
#include "rapidcheck/gtest.h"
#include "test_helpers.h"

TEST(MakeSortedTests, SimpleSortSortedArray) {
    int arr[] = {1,2,3,4,5};
    make_sorted(arr, 5);
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(arr[i], i+1);
    }
    /*
     * Check that we can sort an array that is already sorted.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
}

TEST(MakeSortedTests, SimpleSortReverseSortedArray) {
    int arr[] = {5,4,3,2,1};
    make_sorted(arr, 5);
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(arr[i], i+1);
    }
    /*
     * Check that we can sort an array that is reverse sorted order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
}


TEST(MakeSortedTests, SimpleSortAverageArray) {
    int arr[] = {2,4,1,3,5};
    make_sorted(arr, 5);
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(arr[i], i+1);
    }
    /*
     * Check that we can sort an array where the elements in it are in random order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
}

TEST(MakeSortedTests, SimpleSortArrayWithDuplicates) {
    int arr[] = {2,2,1,5,3};
    make_sorted(arr, 5);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr[2], 2);
    EXPECT_EQ(arr[3], 3);
    EXPECT_EQ(arr[4], 5);
    /*
     * Check that we can sort an array where there are duplicate elements in it.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
}

RC_GTEST_PROP(MakeSortedTests,
              PropertyAfterSortingValuesAreInAscendingOrder,
              ( const std::vector<int>& values)
) {
    if (values.size() == 0) return;
    int arr[values.size()];
    copy_vector_to_array(values, arr);
    make_sorted(arr, values.size());
    for (long unsigned i = 0; i + 1 < values.size(); i++) {
        EXPECT_LE(arr[i], arr[i+1]);
    }
    /* Test that after sorting an array, the values are in ascending order
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
}
