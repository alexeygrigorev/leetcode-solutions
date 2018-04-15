include_directories(include)

file(GLOB SOURCE
    "include/debug.h"
    "src/debug.cpp"
    "include/003_longest_substring.h"
    "src/003_longest_substring.cpp"
    "include/004_median_of_2_sorted_arrays.h"
    "src/004_median_of_2_sorted_arrays.cpp"
    "include/215_kth_element.h"
    "src/215_kth_largest.cpp"
)

add_library(leetcode SHARED STATIC ${SOURCE})
target_include_directories(leetcode PUBLIC include)