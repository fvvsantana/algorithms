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

-- Complete the sockMerchant function below.
{-
I still need to use an unordered set instead of a list. It needs to be
implemented using a hash table.
https://downloads.haskell.org/~ghc/latest/docs/html/libraries/



-}
sockMerchant n ar = countPairs ar []

countPairs [] _ = 0
countPairs (x:xs) ht
    | x `elem` ht = 1 + countPairs xs htWithoutX
    | otherwise = countPairs xs htWithX
    where
        htWithoutX = Data.List.delete x ht
        htWithX = x : ht

{-
main :: IO()
main = do
    n <- readLn :: IO Int

    arTemp <- getLine

    let ar = Data.List.map (read :: String -> Int) . words $ arTemp

    let result = sockMerchant n ar

    putStrLn $ show result
-}

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
