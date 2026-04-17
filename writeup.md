# Google Test And Debugging Writeup

## Things I Thought To Test
1. Get Sorted - make sure it calls sorted on the copy of the array that's being returned
2. Make Sorted - make sure that we don't go out of the bounds of the array with len
3. Copy array - make sure it is an actual copy of the array and not just another pointer
4. Min index - make sure this works for array of size 1 and where min is in the front
5. swap - make sure changes are not only made to local variables
6. parse args - make sure sstring is being used correctly and the memory is not deleted

## Bugs

### Bug 1

### Location

sorting.cpp lines 69-71

```c++
int* temp = a;
  a = b;
  b = temp;
```

### How the bug was located

the first test case for swaping 1 and 2 failed

### Description

the address of local variables was changed
but they were destroyed after the function returned
so nothing actually swapped

### Fix 

instead swaping addresses, we need to swap the values they point to 

```c++
int temp = *a;
  *a = *b;
  *b = temp;
```

### Bug 2

### Location

sorting.cpp line 17

```c++
return ar;
```

### How the bug was located

the test succeeded for an array that did not need to be changed but failed on all other ones

### Description

returned the original array instead of the sorted copy

### Fix

return the correct sorted array

```c++
return sorted_ar;
```

### Bug 3

### Location

sorting.cpp lines 55-57

```c++
if (ar[i] > ar[min_index]) {
      min_index = i;
    }
```

### How the bug was located

in my test of the array it was returning the index of max instead of min

### Description

it replaces the min index with i if value at i is larger instead of smaller than min

### Fix

replace greater than > with less than < symbol

```c++
if (ar[i] < ar[min_index]) {
      min_index = i;
    }
```