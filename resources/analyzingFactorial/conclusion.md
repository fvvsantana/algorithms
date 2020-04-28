# Conclusion
On average, the execution time of the Haskell code was 4 ms.
The execution time of the C++ code was:
factRD: 2144 microseconds
factID: 276 microseconds
factAI: 278 microseconds
factIDS: 6087 microseconds

Except for the factIDS, which uses a stack to calculate factorial, all the C++ executions were faster than the Haskell executions. Even the recursive C++ code was faster than the Haskell code. So for small tests, Haskell is slower than C++ in general.
This is a small test, so it's not conclusive and probably the laziness of Haskell got in his way in this small test.
