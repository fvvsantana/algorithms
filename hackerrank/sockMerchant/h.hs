import Data.List
import qualified Data.HashSet as Hamt

main = interact $ show . solve . map read . tail . words

solve ar = countPairs ar Hamt.empty

countPairs [] _ = 0
countPairs (x:xs) hs
    | Hamt.member x hs = 1 + countPairs xs hsWithoutX
    | otherwise = countPairs xs hsWithX
    where
        hsWithoutX = Hamt.delete x hs
        hsWithX = Hamt.insert x hs

{-
main = do
    n <- getLine
    ar <- getLine
    let out = solve . map (\s -> read s :: Int) . words $ ar
    print out
-}

-- Complete the sockMerchant function below.
{-
I still need to use an unordered set instead of a list. It needs to be
implemented using a hash table.
https://downloads.haskell.org/~ghc/latest/docs/html/libraries/
This can be used, O(1):
https://hackage.haskell.org/package/unordered-containers-0.2.4.0/docs/Data-HashMap-Lazy.html
https://subscription.packtpub.com/book/big_data_and_business_intelligence/9781783286331/4/ch04lvl1sec55/using-a-high-performance-hash-table
This is also O(1), because it's built over hamt that has O(1) average complexity:
https://hackage.haskell.org/package/unordered-containers-0.2.10.0/docs/Data-HashSet.html
Also looking at the implementation of the HashTable it's also O(1):
https://hackage.haskell.org/package/base-4.2.0.0/docs/Data-HashTable.html


https://stackoverflow.com/questions/58888145/any-good-resources-on-data-structures-and-algorithms-in-haskell

------- Data Structures -------
Data.Array
Data.Bits
Data.Either
Data.Graph
Data.Graph.Inductive
Data.HashTable
Data.IntMap
Data.IntSet
Data.IORef
Data.Ix
Data.Lists
Data.Map
Data.Maybe
Data.Monoid
Data.PackedString
Data.Queue
Data.Ratio
Data.Set
Data.STRef
Data.Tree
Data.Tuple
Data.Typeable
Data.Unique
Data.Word
-- How to generate Co-Data Structures?

------- Algorithms -------
Recursive.
Dynamic programming.
Backtracking.
Divide and conquer.
Greedy algorithm.
Probabilistic algorithm.
Randomized algorithm.


Finally, my choice is to use the HashSet:
https://hackage.haskell.org/package/unordered-containers-0.2.10.0/docs/Data-HashSet.html

-}
