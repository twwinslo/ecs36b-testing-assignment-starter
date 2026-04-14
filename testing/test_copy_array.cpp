#include <cstdlib>
#include <vector>
#include <algorithm>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "sorting.h"
#include "test_helpers.h"
#include "rapidcheck/gtest.h"

TEST(CopyArrayTests, SimpleValuesAreSame) {
    int arr[] = {1,2,3,4,5};
    int* arr_copy = copy_array(arr,5);
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(arr[i], arr_copy[i]);
    }
    free(arr_copy);
    /*
     * Check that the values in the copy are the same as the values in the original array.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */


}

TEST(CopyArrayTests, SimpleOriginalDoesNotChange) {
    int arr[] = {1,2,3,4,5};
    int* arr_copy = copy_array(arr,5);
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(arr[i], i+1);
    }
    free(arr_copy);
    /*
     * Check that the  values in the original array did not change.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */

}

TEST(CopyArrayTests, SimpleCopyWasMade) {
    int arr[] = {1,2,3,4,5};
    int* arr_copy = copy_array(arr,5);
    for (int i = 0; i < 5; i++) {
        EXPECT_NE(arr+i, arr_copy+i);
    }
    free(arr_copy);
    /*
     * Check that a copy was actually made
     * (ar and copy point to different locations in memory and no parts of the two arrays overlap)
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */

}


RC_GTEST_PROP(CopyArrayTests,
              PropertyValuesAreSame,
              (const std::vector<int>& values)
) {
    int arr[] = copy_vector_to_array(values);
    int* copy = copy_array(arr, values.size());
    for (int i = 0; i < values.size(); i++) {
        EXPECT_EQ(arr[i], copy[i]);
    }
    free(copy);
    /*
     * Check that the values in the copy are the same as the values in the original array.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */

}

RC_GTEST_PROP(CopyArrayTests,
              PropertyOriginalDoesNotChange,
              (const std::vector<int>&values)
) {
    int arr[] = copy_vector_to_array(values);
    int* copy = copy_array(values, values.size());
    for (int i = 0; i < values.size(); i++) {
        EXPECT_EQ(arr[i], values[i]);
    }
    free(copy);
    /*
     * Check that the  values in the original array did not change.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */

}

RC_GTEST_PROP(CopyArrayTests,
              PropertyCopyWasMade,
              (const std::vector<int>&values)
) {
    int arr[] = copy_vector_to_array(values);
    int* copy = copy_array(arr, values.size());
    for (int i = 0; i < values.size(); i++) {
        EXPECT_NE(arr + i, copy + i);
    }
    free(copy);
    /*
  * Check that a copy was actually made
  * (ar and copy point to different locations in memory and no parts of the two arrays overlap)
  * Don't forget to free any memory that was dynamically allocated as part of your test.
  */

}



