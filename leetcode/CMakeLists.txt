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
    "include/347_top_k_frequent_test.h"
    "src/347_top_k_frequent.cpp"
    "include/053_maximum_subarray.h"
    "src/053_maximum_subarray.cpp"
    "include/152_maximum_product_subarray.h"
    "src/152_maximum_product_subarray.cpp"
    "include/002_add_two_numbers.h"
    "src/002_add_two_numbers.cpp"
    "include/020_valid_parentheses.h"
    "src/020_valid_parentheses.cpp"
    "include/001_two_sum.h"
    "src/001_two_sum.cpp"
    "include/032_longest_valid_parentheses.h"
    "src/032_longest_valid_parentheses.cpp"
    "include/005_longest_palindrome_substring.h"
    "src/005_longest_palindrome_substring.cpp"
    "include/006_zigzag_conversion.h"
    "src/006_zigzag_conversion.cpp"
)

add_library(leetcode SHARED STATIC ${SOURCE})
target_include_directories(leetcode PUBLIC include)