# How to solve programming challenges
* Understand the problem
* Try to classify the problem: (the main part of the challenge)
    * Search for solution. (The solution is a secret)
    * Building a solution. (the solution is not a secret, the problem is to make an algorithm to create a solution.)
    * Table testing

# For search problems:
* Uniquely represent a solution. e.g.: [rowId, colId]
* Formalize your space of search. e.g.: a matrix N*N.
* Find the brute force algorithm. (get complexity in time and space).
* Understand:
    * How to build a solution
    * How to verify that a solution is the best.
* Identify duplicated/non-optimized computations.
* Identify relationships among solutions.
* Come with a bottom-up solution, or divide-and-conquer.
* Table testing
    (Spend some time after getting the solution to do some table testing and get more used to your algorithm. This will help you to implement it after.)



* Tips for finding solution:
    * Use hash table.
* Tips for coding:
    * Use swap to reuse code. (problem 4-Median-of-Two-Sorted-Arrays).
    * When a variable have a complex meaning, write it down on comment.
    * The index i means how many elements there are before it.
    State machine:
    * When you have a loop that changes the state multiple times, you could use a state machine.
    * If a state happens once and then finishes, try to avoid putting it into the state machine.
    * If you don't know what is the condition of the while, put some condition anyway, then build your code using that condition as a premise. (much more clean code doing this way)
    * Never forget, stl.end() is not the last element;
    * Non hashable objects cannot be used as keys to maps and sets.
* Tips for dynamic programming:
    * Play around with some examples to understand the algorithm.
    * See that the number of solutions is exponential, analyze the brute force solution.
    * Define the solution recursively.
    * On dynamic programming, try to use indices of arrays instead of its elements when formulating the recurrence.
* Tips for backtracking:
    * Think recursively.

# Building a solution:
* Represent the solution.
* Find the algorithm to build the solution.
* Try to use data structures.
* Try to find unnecessary information you computed.
* Tips:
    * Think recursively.


# Space complexity tips
* Always consider the initial string for space complexity. In this way, you can implement whatever O(n) solution without worrying about space

# Data structures tips:
* When you want to use an array of characters, or a linked list of characters, sometimes it's better to use a string.
* When there is overflow involved, try to use a bigger datatype.
* Sometimes you can use strings to take the digits of any number.
* Bitmasks: create values and masks using the hexadecimal notation 0xFFFF, use bitwise operations like &, |, ^, ~, <<, >>, etc.
* I avoided using sets in the "46-Permutations" by swapping elements in the array. Also, looped recursively through the given array, instead of looping through the permutations (answers).



# To find laws
* See in the matrix what are the relationships among solutions
    * Union
    * Intersection
    * Concatenation
    * Difference
    * Containment
    * Complement
    * Order
* Given these relationships, check if there are any laws that involve these relationships:
    * Substring and containance about repeated characters.

# Important laws
## Repeated characters on string
    * If a string doesn't have any repeated characters, then a substring won't have any repeated characters.
## Median
    * Definition: number of greater elements and number of smaller elements are equal.
## Palindromes
    Two important relationships:
    1) (Containment + same symmetry axis) between two palindromes:
          |-A-|    
        a b a b a
        |---B---|  
        You can use A to calculate B, expanding from A.
    2) (Containment + different symmetry axes) among three palindromes:
        |-A-|   |-B-|
        a b a b a b a
        |-----C-----|
        Given the long palindrome C, a palindrome A contained in C will always have a symmetric palindrome B, also contained in C.

    Manacher's algorithm uses these relationships, uses a LPSL array (Longest Palindromic Sub-string Length array) to find the longest palindromic sub-string of a given string.
    The use of separation bars in this algorithm allows treating every symmetry axis as centered in a character.
## The way that the longest increasing subsequence works
    See the O(nlogn) solution: https://leetcode.com/problems/longest-increasing-subsequence/solution/

# Why heap has insertion O(1)
Average number of steps in insertion = 1*1/2 + 2 * 1/4 + 3 * 1/8 + 4 * 1/16 ... = sum(n/2^n) = constant value.
sum(n/2^n) converges absolutely, this is verifiable using the convergence ratio test.
Deletion is O(log n) though

# Heap tip (Kth Largest Element in a Stream)
For getting the Kth Largest Element in a Stream, you can use heap, given the constraints. Adding and deleting elements is possible using 1 or 2 heaps. But at the same time, accessing the Jth and the Kth largest elements in a stream, it's better using a tree with all elements.
