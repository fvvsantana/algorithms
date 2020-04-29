# How to solve programming challenges
* Understand the problem
* Try to classify the problem: (the main part of the challenge)
    * Search for solution. (The solution is a secret)
    * Building a solution. (the solution is not a secret, the problem is to make an algorithm to create a solution.)

# For search problems:
* Uniquely represent a solution. e.g.: [rowId, colId]
* Formalize your space of search. e.g.: a matrix N*N.
* Find the brute force algorithm. (get complexity in time and space).
* Identify duplicated/non-optimized computations.
* Come with a bottom-up solution, or divide-and-conquer.
* Create laws like:
    * If there isn't repeated characters in a string, then there isn't in a substring.
    * If I computed that, I get the results of all of these sub problems.
* These laws would help you to identify non-optimizations.

* Tips:
 * Use hash table.
 *

# Building a solution:
* Represent the solution.
* Find the algorithm to build the solution.
* Tips:
    * Think recursively.


# General tips
* The size of a hash table depends not only on how many things you put inside of it, but depends on the size of the "alphabet" of keys. The number of possible values for keys also determines the size of the hash table. So be careful with Sets, Maps and HashStuff.
