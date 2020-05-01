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



* Tips:
 * Use hash table.
 * Keep pseudo-code more pseudo.

# Building a solution:
* Represent the solution.
* Find the algorithm to build the solution.
* Tips:
    * Think recursively.


# Space complexity tips
* Size of hash table: O(max(m+n))
    * m: number of keys inserted.
    * n: number of possible values that a key can have. (alphabet).
    * Affects HashSets and HashMaps.

# To find laws
* See in the matrix what are the relationships among solutions
    * Union
    * Intersection
    * Concatenation
    * Difference
    * One solution containing another
    * Complement
    * Order
* Given these relationships, check if there are any laws that involve these relationships:
    * Substring and containance about repeated characters.

# Important laws
## Repeated characters on string
    * If a string doesn't have any repeated characters, then a substring won't have repeated characters.
## Median
    * Definition: number of greater elements and number of smaller elements are equal.
