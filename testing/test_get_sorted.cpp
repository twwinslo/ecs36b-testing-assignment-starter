#include <cstdlib>
#include "gtest/gtest.h"
#include "sorting.h"
#include "test_helpers.h"
#include "rapidcheck/gtest.h"

TEST(GetSortedTests, SimpleSortSortedArray) {
    int arr[] = {1,2,3,4,5};
    int* arr_copy = get_sorted(arr, 5);
    for (int i =0; i < 5; i++) {
        EXPECT_EQ(arr_copy[i], i+1);
    }
    free(arr_copy);
    /*
     * Check that we can sort an array that is already sorted.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */


}

TEST(GetSortedTests, SimpleSortReverseSortedArray) {
    int arr[] = {5,4,3,2,1};
    int* arr_copy = get_sorted(arr, 5);
    for (int i =0; i < 5; i++) {
        EXPECT_EQ(arr_copy[i], i+1);
    }
    free(arr_copy);
    /*
     * Check that we can sort an array that is reverse sorted order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */

}

TEST(GetSortedTests, SimpleSortAverageArray) {
    int arr[] = {2,4,5,1,3};
    int* arr_copy = get_sorted(arr, 5);
    for (int i =0; i < 5; i++) {
        EXPECT_EQ(arr_copy[i], i+1);
    }
    free(arr_copy);
    /*
     * Check that we can sort an array where the elements in it are in random order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */


}

TEST(GetSortedTests, SimpleSortArrayWithDuplicates) {
    int arr[] = {2,2,5,1,2};
    int* arr_copy = get_sorted(arr, 5);
    EXPECT_EQ(arr_copy[i], i+1);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr[2], 2);
    EXPECT_EQ(arr[3], 2);
    EXPECT_EQ(arr[4], 5);
    free(arr_copy);
    /*
     * Check that we can sort an array where there are duplicate elements in it.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */


}

TEST(GetSortedTests, SimpleOriginalDoesNotChange) {
    int arr[] = {1,2,3,4,5};
    int* arr_copy = get_sorted(arr, 5);
    for (int i =0; i < 5; i++) {
        EXPECT_EQ(arr[i], i+1);
    }
    free(arr_copy);
    /*
     * Check that the original array was not modified.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */


}

TEST(GetSortedTests, SimpleCopyWasMade) {
    int arr[] = {1,2,3,4,5};
    int* arr_copy = get_sorted(arr, 5);
    for (int i =0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            EXPECT_NE(arr+i, arr_copy + j);
        }
    }
    free(arr_copy);
    /*
     * Check that the sorted array is copy of the original array in sorted order.
     * (ar and copy point to different locations in memory and no parts of the two arrays overlap)
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */


}


RC_GTEST_PROP(GetSortedTests,
              PropertyAfterSortingValuesAreInAscendingOrder,
              ( std::vector<int> values)
) {
    /* Check that after sorting an array, the values are in ascending order
     * Don't forget to free any memory that was dynamically allocated as part of this test
     */

}

RC_GTEST_PROP(GetSortedTests,
              PropertyOriginalDoesNotChange,
              (const std::vector<int>&values)
) {
    /*
     * Check that the original array was not modified.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    ;
}

RC_GTEST_PROP(GetSortedTests,
              PropertyCopyWasMade,
              (const std::vector<int>&values)
) {
    /*
     * Check that the sorted array is copy of the original array in sorted order.
     * (ar and copy point to different locations in memory and no parts of the two arrays overlap)
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */

}











