Brief description of the solutions


## 3. Longest substring without repeating characters (medium)

* [description](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
* [solution](https://github.com/alexeygrigorev/leetcode-solutions/blob/master/leetcode/src/003_longest_substring.cpp)

Input: 
* `str: string`

Keep:
* `start[i]`: says where the current longest substring starts (it ends at `i`)
* map `char -> index`: the position where the char was seen previously, -1 if not seen so far

to calculate `start[i+1]`
* `c = str[i + 1]` - the character at position `i + 1`
* let `m = map[c]` - where we saw `c` previously
* if `m` is before `start[i]`, then `start[i+1] = start[i]`
* else, `start[i+1] = m + 1`

That is, if `c` was seen after `start[i]`, we move `start[i+1]` right after `map[c]`


## 5. Longest Palindrome Subsequence (medium)

* a DP problem 
* [description](https://leetcode.com/problems/longest-palindromic-substring/)
* [solution](https://github.com/alexeygrigorev/leetcode-solutions/blob/master/leetcode/src/005_longest_palindrome_substring.cpp)

Input: 
* string `s` of len `n`

Keep:
* `palindromes[n][n]` of booleans
* `palindromes[i][j]` means that `s[i..j]` is a palindrome

`s[i..j]` is a palindrome if
* `s[i] == s[j]` and
* `s[i+1..j-1]` is a palindrome as well

So, `palindromes[i][j] = true` if
* `s[i] == s[j]`
* `palindromes[i+1][j-1] == true`

Then select the longest one 


## 10. Regular Expression Matching (hard)

* [description](https://leetcode.com/problems/regular-expression-matching/)
* [solution](https://github.com/alexeygrigorev/leetcode-solutions/blob/master/leetcode/src/010_regexp.cpp)

Given:
* a string `s`
* a pattern `p` supporting "`.`" and "`?`"
    * `.` matches anything
    * `?` matches 0 or more preceeding elements

Task:
* return true if string matches the pattern, false otherwise

Notation:
* `s[1..]` means substring of `s` from 1 till end


### Recursion

It can be solved using recursion

`match(s, p)`
* if `s` and `p` are empty, return true
* if `s` is empty, but `p` is not
    * if the first char of `p` is optional (has `*` after)
    * then return `match("", p[2..])` 
    * otherwise return `false`
* if the first pattern letter is optional (i.e. `p[1] == '*'`):
    * we need to handle two cases: when `p[0] == '.'` and when it's some character
    * the any matcher case (`p[0] == '.'`):
        * since it matches to anything, we just try to move forward
        * try `match(s[1..], p)`
        * try `match(s[1..], p[2..])`
        * try `match(s, p[2..])`
    * specific matcher case:
        * let `c = p[0]`
        * let `i = 0` and move `i` forward while `s[i] == c`
            * and then try `match(s[i..], p[2..])`
        * if not successfull:
        * try `match(s[1..], p)`
        * try `match(s[1..], p[2..])`
        * try `match(s, p[2..])`
* if `p[0] == '.'` or `s[0] == p[0]`
    * return `match(s[1..], p[1..])`
* return `false`


### Dynamic Programming 

TODO


## 15. 3Sum

* [description](https://leetcode.com/problems/3sum/)
* [solution](https://github.com/alexeygrigorev/leetcode-solutions/blob/master/leetcode/src/015_three_sum.cpp)


Solution with a hash:

* count every element with a hash
* then go through each (element, count) pair
* if it's `0` and appears 3 or more time, output `(0, 0, 0)`
* if it's some `a` (`a != 0`) that appears 2 or more times
    * check if there's `c = -2*a`
    * if yes, output `(a, a, c)`
* if `a` appears only once
    * check through all `b != a` and for each `b` check if there'c `c = -(a-b)`
    * if yes, output `(a, b, c)`
* use set to get rid of duplicates


Solution with sorting

* sort the array
* for each element `a` in this array
* fast-forward it if it's equals to the previous element (to avoid duplicates)
* then do a 2-sum bi-directional pass:
    * let `target = -a`
    * let `b` be the element next to `a`, and `c` - the most right element
    * if `s = a + b == target`
        * output `(a, b, c)`
        * to skip duplicates:
        * move `b` right till it changes value
        * move `c` left till it changes value
    * if `s < target` - move `b` right
    * if `s > target` - move `c` left


## 33. Search in Rotated Sorted Array (medium)

* [description](https://leetcode.com/problems/search-in-rotated-sorted-array/)
* [solution](https://github.com/alexeygrigorev/leetcode-solutions/blob/master/leetcode/src/033_search_in_rotated_sorted_array.cpp)

Problem:
* Array is first sorted and then shifted, the shift size is not known.
* You need to find the target in this array
* "pivot" - the index where the sorted order breaks
    * e.g. 3, 4, 5, 0, 2, 5 is the pivot
* there are no duplicates

Algorithm `RotatedSearch(array A, target t, left l, right r)`:
* if `l >= r`
    * return `-1` - not found
* let 
    * `m = l + (r - l) / 2` - middle index
    * `start = A[l]`, `mid = A[m]`, `end = A[r]`
* if `target` is `start`, `mid` or `end`
    * then return the appropriate index
* if `start <= target < mid`:
    * `A` on the left from `m` is sorted and `t` must be there
    * return `RotatedSearch(A, t, l, m - 1)`
* if `mid < target <= end`:
    * `A` on the right from `m` is sorted and `t` must be there
    * return `RotatedSearch(A, t, m + 1, r)`
* the above was the usual binary search case
    * but since none of the conditions above checked, we know the order breaks somewhere
    * so we need to find the "pivot" - where it breaks
* if `mid > right`:
    * pivot is on the right,
    * and the usual binary search condition didn't work for the left part
    * so the target must be on the right
    * return `RotatedSearch(A, t, m + 1, r)`
* if `mid < left`:
    * same logic as above, but here go to the left
    * return `RotatedSearch(A, t, l, m - 1)`

Duplicates
* in presence of duplicates make sure the start and end aren't equal
* see leetcode 81



## 53. Maximum Subarray Sum (easy)

* a DP problem
* [description](https://leetcode.com/problems/maximum-subarray/)
* [solution](https://github.com/alexeygrigorev/leetcode-solutions/blob/master/leetcode/src/053_maximum_subarray.cpp)

Input: 
* `arr`: an array of integers (both positive and negative)

Keep:
* `sum[i]`: the maximum sum for subarray of `0..i` (not necessarily starting at `0`)

`sum[i+1]`:
* if adding `sum[i] + arr[i+1] > arr[i+1]`, then `sum[i+1] = sum[i] + arr[i+1]`
* else, `sum[i+1] = arr[i+1]`

At the end choose max of all `sum[i]`'s 

If `sum[i]` is negative, then no matter what we have at `arr[i+1]`, it will no help, so we reset `sum[i+1]` to the new element `arr[i+1]`, otherwise keep the previous sum.

Links:
* https://en.wikipedia.org/wiki/Maximum_subarray_problem


## 72. Edit Distance (hard)

* a DP problem
* [description](https://leetcode.com/problems/edit-distance/description/)
* [solution](https://github.com/alexeygrigorev/leetcode-solutions/blob/master/leetcode/src/072_edit_distance.cpp)

Input:
* string `s1` of size `n1`
* string `s2` of size `n2`

Keep
* `distance[n1 + 1][n2 + 1]` where
* `distance[i][j]` is the edit distance for `s1[:i+1][:j+1]`

`distance[i][j]`
* `substitution_cost`: if `s1[i+1] == s2[j+1]`
    * then there's no cost for inserting the letter, so just take `dinstance[i-1][j-1]`
    * else, it's `distance[i-1][j-1] + 1`
* `delete_cost`: `distance[i-1][j] + 1`
* `insertion_cost`: `distance[i][j-1] + 1`



Links:
* https://en.wikipedia.org/wiki/Levenshtein_distance



## 81. Search in Rotated Sorted Array II (medium)

* [description](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/)
* [solution](https://github.com/alexeygrigorev/leetcode-solutions/blob/master/leetcode/src/081_search_in_rotated_sorted_array_2.cpp)
* same as 33. Search in Rotated Sorted Array (medium), but with duplicates

Solution:
* very similar to 33, just needs some adjustments
* make sure `A[start] != A[end]`
    * this can be done by moving `end` to left until `A[start] != A[end]` is satisfied
* the rest is the same 


## 84. Largest Rectangle in Histogram

* [description](https://leetcode.com/problems/largest-rectangle-in-histogram/)
* [solution](https://github.com/alexeygrigorev/leetcode-solutions/blob/master/leetcode/src/084_max_hist_rectangle.cpp)


* Let `hist` be the array with heights
* and let `n` be the length of `hist`

Naive:

* `max_area = 0`
* for each index `i = 0 .. n - 1`
* let `min_height = inf`
    * for `j = i .. 0`
    * update `min_height = min(min_height, hist[j])`
    * calculate width of the area as `width = j - i + 1`
    * `area = min_height * width`
    * update `max_area = max(max_area, area)`
* return `max_area`


Solution with stack:

Idea:

* uses the same idea as the naive approach:
* look for all gradually decreasing values that are before current index `i`
* calculate area for each `width`
* use stack to efficiently find decreasing values

Solution:

* create empty stack `s`
* let `i = 0` and while `i < n`, do
* if `s` is empty or `hist[i]` is larger or equal to `hist[s.top]`:
    * put `i` to `s`
    * increment `i`
* otherwise:
    * pop `j` from `s`
    * height is `h = hist[j]`
        * this is the largest value currently in `s` 
        * (and it's also higher than the current value at `hist[i]`)
    * calculate width of area as `w = i - 1 - s.top` or `w = i` if `s` is empty
        * we calculate the area formed by the previous bar, hence use `i-1`
        * `s.top` contains the previous min element
    * let `area = h * w`
    * update `max_area = max(max_area, area)`
* if stack is not empty, repeat the above procedure one more time
* return `max_area`


Divide-and-Conquer

* another approach is to use recursion
* find the index `m` of the min value between indexes `left` and `right`
* then max area is the maximum of
    * height of this min bar
    * maximal area of the histogram on the left of `m`
    * maximal area of the histogram on the right of `m`
* to find the min value efficiently, use segment tree


## 85. Maximal Rectangle

* [description](https://leetcode.com/problems/maximal-rectangle/description/)
* [solution](https://github.com/alexeygrigorev/leetcode-solutions/blob/master/leetcode/src/085_maximal_rectangle.cpp)


DFS solution:

* from each cell that doesn't belong to any rectangle
* run a DFS to find many rectangles as possible:
    * start with a simple cell
    * expand it to left, up, right, down
    * when no longer possible to expand, add to the left of discovered rectangles
* then go through all the rectangles and get the one with max area

Largest area in histogram solution:

* use solution from 84. Largest Rectangle in Histogram
* build a histogram from each row:
    * from each cell go up while cell contains 1
* then run solution from 84

DP solution:

* keep 3 helper arrays:
    * `heights[i][j]`: how many ones are above the cell `m[i,j]`
    * `left[i][j]`: the index where the current sequence of 1's start
    * `right[i][j]`: the index where the current sequence of 1's end
* calculating `heights[i+1][j]` from `heights[i][j]` is easy
* calculating `left[i+1][j]`:
    * for each row `i` we maintain index `left_start` where the current sequence of 1s start in this row
    * if `m[i,j] == 0`, then
        * let  `left[i+1][j] = 0`
        * let `left_start = j + 1` - we point it to the next cell, if it's also 0, it'll be incremented anyways
    * if `m[i,j] == 1`:
        * let `left[i+1][j] = max(left[i][j], left_start)`
        * if `left_start` is bigger than `left[i][j]` (index in the cell above), then there's no proper rectangle above, so it's in this row
        * if `left[i][j]` is bigger, then there's a rectangle
* calculating `right[i+1][j]`:
    * similar to `left`, but
    * we go through values of `j` from the end
    * we initialize `right_end` with `m`, where `m` is the number of columns in the matrix
* calculating area for a rectangle at `m[i+1][j]`:
    * `height = heights[i+1][j]`
    * `width = right[i+1][j] - left[i+1][j] + 1`
    * `area = height * width`


## 87. Scramble String

* [description](https://leetcode.com/problems/scramble-string/)
* [solution](https://github.com/alexeygrigorev/leetcode-solutions/blob/master/leetcode/src/087_scramble_string.cpp)


Recursive solution:

* check if `s1` and `s2` are anagrams - if not, `s2` is not scrambled `s1`
* if `s1 == s2`, then return true
* now try to split `s1` in all possible ways - this way we go through ways of building the tree
* let `i` be index between 1 and `len(s1) - 1`
* `s1[:i]` goes to the left child, `s1[i:]` goes to the right child
* if we build the tree this way (i.e. by splitting at `i`), then there are two possible ways to split `s2`:
    * we split `s2[:i]` and `s2[i:]` - if string was not scrambled
    * or we split `s2[:n-i]` and `s2[n-i:]` - in case the string was scrambled
* so then we return true if:
    * `s2[:i]` is scrambled version of `s1[:i]` AND `s2[i:]` is scrambled `s1[i:]`
    * OR
    * `s2[n-i:]` is scrambled version of `s1[:i]` AND `s2[:n-i]` is scramble `s1[i:]`
* otherwise, return false


## 115. Distinct Subsequences

* [description](https://leetcode.com/problems/distinct-subsequences/)
* [solution](https://github.com/alexeygrigorev/leetcode-solutions/blob/master/leetcode/src/115_distinct_subsequences.cpp)

Given a string `s` and a string `t`, count the number of distinct subsequences of `s` which equals `t`.


Recursive solution:

* let `pos_t` be current position in `t` and `pos_s` be the current position in `s`
* if `pos_t` is out out bounds - `t` "is empty", so count is 1
* let `count = 0`
* now for all indexes `i` in `s` starting from `pos_s`:
    * if `s[i] == t[pos_t]`
    * then recursively invoke the function and include results into `count`
* return `count`
* easy to add memoization: keep a 2d array `memo`:
    * `memo[i][j]` contains count for `i=pos_s` and `j=pos_t`
    * if `memo[i][j] == -1`, not calculated yet

DP:

* keep a table `dp[len(t) + 1][len(s) + 1]`
* initialize `dp`:
    * first row is all ones: an empty string is always contained only once
    * first column is all zeros (except 0,0): empty string cannot contain a non-empty one
* `dp[i][j]` is
* if `s[i] != t[j]`, then `dp[i][j-1]`
    * that's the previous value from the same row
    * i.e. if the characters don't match, then with `s[i]` the number of times `t[0..i]` occurs in `s[0..j]` is the same as the number of times `t[0..i]` occurs in `s[0..j-1]`
* otherwise, `dp[i][j-1] + dp[i-1][j-1]`
    * the number of occurrences of `t[0..i]` in `s[0..j]` is the sum of
    * number of times `t[0..i-1]` occurred in `s[0..j-1]` and
    * number of times `t[0..i]` occurred in `s[0..j-1]`

Example:

* `b` occurred 3 times in `babgb`
* `ba` occurrend 1 time in `babgb`
* if we consider `babgb`+`a` and `ba`, it's 4:
    * `ba` has already appeared 1 time
    * and `b` appeared 3 times, so by adding `a` to `s` all 3 get completed



## 152. Maximum Subarray Product

* a DP problem
* [description](https://leetcode.com/problems/maximum-product-subarray/)
* [solution](https://github.com/alexeygrigorev/leetcode-solutions/blob/master/leetcode/src/152_maximum_product_subarray.cpp)

Input: 
* `arr`: an array of integers (both positive and negative)

Keep:
* `current_min[i]`: the minimum product of subarray ending at `i`
* `current_max[i]`: the maximum product of subarray ending at `i`

Step:
* `current_min[i+1] = min(A[i+1], current_min[i] * A[i+1], current_max[i] * A[i+1])`
* `current_max[i+1] = max(A[i+1], current_min[i] * A[i+1], current_max[i] * A[i+1])`

At the end choose max of all `current_max[i]`'s 

Because the product of two negative numbers is positive, we need to keep two tables: one for min and one for max. 

See also:
* 53. Maximum Subarray Sum (easy)


## 207. Course Schedule (medium)

* a graph problem
* [description](https://leetcode.com/problems/course-schedule/)
* [solution](https://github.com/alexeygrigorev/leetcode-solutions/blob/master/leetcode/src/207_course_schedule.cpp)


In this problem we need to find loops in a graph

With usual DFS loops are easy to find:
* mark nodes as `VISITING` and `VISITED`
* if you do DFS and visit a node that is marked as `VISITING`, then you have a loop

Translating the recursion version to stack is a bit difficult
* need to keep some information about each node in the stack

`Stack-based-DFS(graph G, starting node s)`
* initialize empty stack
* for each `node` keep status
    * `NOT_VISITED` if the node is not visited yet (initially all nodes get that)
    * `VISITING` if the node is being visited
    * `VISITED` if the node is processed already
* push `(s, 0)` to stack, where
    * `s` is the node we want to traverse
    * `0` is the counter for how many times we visited the node
* while stack is not empty:
    * pop `(node n, count c)` from stack
    * if `status[n] == VISITING` and `c > 0`:
        * we have a loop 
    * if `c > 0`:
         set `status[n] = VISITED`, continue
    * set `status[n] = VISITING`
    * push `(n, 1)` to stack
    * for each edge `(n, o)` coming from `n`:
        * if `status[o] != VISITED`, push `(o, 0)` to stack
* if reached here, no loop is detected


## 295. Find Median from Data Stream (hard)

* [description](https://leetcode.com/problems/find-median-from-data-stream/)
* [solution](https://github.com/alexeygrigorev/leetcode-solutions/blob/master/leetcode/src/295_median.cpp)

Given
* a stream of integers 

Task:
* at any point of time return the median of the stream

Idea:
* split all the data into two parts: less than median and greater then median
* to do it, keep two heaps
    * `left_max_heap`: a max heap that stores everything that is less then median
    * `right_min_heap`: a min heap that stores everything that is greater than median
* heaps can return smallest (largest) element: this is our median

Solution:
* add each incoming number to the `right_min` heap
* then extract the min element from this `right_min` heap and put it to the `left_max` heap
* to keep the heaps balanced
    * check if there's more elements in the left heap
    * if yes, pop the max element to the `right_min` queue
* this way there is equal number of elements in both heaps 



## 815. Bus routes (hard)

* a graph problem
* [description](https://leetcode.com/problems/bus-routes/)
* [solution](https://github.com/alexeygrigorev/leetcode-solutions/blob/master/leetcode/src/815_bus_routes.cpp)

Given:
* `N` bus routes, each is a list of stops
    * `[[1, 2, 7], [3, 6, 7]]`
    * bus 0's stops are 1, 2, 7; 1's are 3, 6, 7
* start `S` and end `T`

Goal:
* find the minimal number of busses we need to take to get from `S` to `T`

Solution:
* build index stop->bus
* build a graph from this index 
* use BFS to find the shortest path

Index:
* just go over each bus routes and do:
* `index[bus].append(bus_stop)`

Graph:
* for each bus stop `b` in the index
* if there is two or more stops, then add the connection to the graph:
    * for all pairs `(i != j)` of the bus stop `b`
    * `graph[bus_i].append(bus_j)` 
* add two artificial nodes with start and end
