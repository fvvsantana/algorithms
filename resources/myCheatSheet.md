# How to solve programming challenges
* Understand the problem
* Try to classify the problem: (the main part of the challenge)
    * Search for solution. (The solution is a secret)
    * Building a solution. (the solution is not a secret, the problem is to make an algorithm to create a solution.)

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



* Tips for finding solution:
    * Use hash table.
* Tips for coding:
    * Use swap to reuse code. (problem 4-Median-of-Two-Sorted-Arrays).
    * When a variable have a complex meaning, write it down on comment.
    * The index i means how many elements there are before it.
    State machine:
    * When you have a loop that changes the state multiple times, you could use a state machine.
    * If a state happens once and then finishes, try to avoid putting it into the state machine.

# Building a solution:
* Represent the solution.
* Find the algorithm to build the solution.
* Tips:
    * Think recursively.


# Space complexity tips
* Always consider the initial string for space complexity. In this way, you can implement whatever O(n) solution without worrying about space

# Data structures tips:
* When you want to use an array of characters, or a linked list of characters, sometimes it's better to use a string.
* When there is overflow involved, try to use a bigger datatype.
* Sometimes you can use strings to take the digits of any number.
* Bitmasks: create values and masks using the hexadecimal notation 0xFFFF, use bitwise operations like &, |, ^, ~, <<, >>, etc.



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
