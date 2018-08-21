Brief description of the solutions:


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
        * let $i = 0$ and move `i` forward till `s[i] == c`
            * and then try `match(s[i..], p[2..])`
        * if not successfull:
        * try `match(s[1..], p)`
        * try `match(s[1..], p[2..])`
        * try `match(s, p[2..])`
* if `p[0] == '.'` or `s[0] == p[0]`
    * return `match(s[1..], p[1..])
* return `false`


### Dynamic Programming 

TODO



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


## 81. Search in Rotated Sorted Array II (medium)

* [description](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/)
* [solution](https://github.com/alexeygrigorev/leetcode-solutions/blob/master/leetcode/src/081_search_in_rotated_sorted_array_2.cpp)
* same as 33. Search in Rotated Sorted Array (medium), but with duplicates

Solution:
* very similar to 33, just needs some adjustments
* make sure `A[start] != A[end]`
    * this can be done by moving `end` to left until `A[start] != A[end]` is satisfied
* the rest is the same 



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
