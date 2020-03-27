{-# LANGUAGE FlexibleInstances, UndecidableInstances, DuplicateRecordFields #-}

module Main where

import Control.Monad
import Data.Array
import Data.Bits
import Data.List
import Data.List.Split
import Data.Set
import Debug.Trace
import System.Environment
import System.IO
import System.IO.Unsafe

import qualified Data.HashSet as Hamt

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
sockMerchant n ar = countPairs ar Hamt.empty

-- Test putting hamt.empty as the second argument
countPairs [] _ = 0
countPairs (x:xs) hs
    | Hamt.member x hs = 1 + countPairs xs hsWithoutX
    | otherwise = countPairs xs hsWithX
    where
        hsWithoutX = Hamt.delete x hs
        hsWithX = Hamt.insert x hs


main :: IO()
main = do
    n <- readLn :: IO Int

    arTemp <- getLine

    let ar = Data.List.map (read :: String -> Int) . words $ arTemp

    let result = sockMerchant n ar

    putStrLn $ show result

{-

readMultipleLinesAsStringArray :: Int -> IO [String]
readMultipleLinesAsStringArray 0 = return []
readMultipleLinesAsStringArray n = do
    line <- getLine
    rest <- readMultipleLinesAsStringArray(n - 1)
    return (line : rest)

main :: IO()
main = do
    stdout <- getEnv "OUTPUT_PATH"
    fptr <- openFile stdout WriteMode

    n <- readLn :: IO Int

    arTemp <- getLine

    let ar = Data.List.map (read :: String -> Int) . words $ arTemp

    let result = sockMerchant n ar

    hPutStrLn fptr $ show result
    -- putStrLn $ show result

    hFlush fptr
    hClose fptr
-}
