-- import Criterion.Measurement as CM
import Criterion.Main
-- import System.TimeIt

-- This factorial function is purposely wrong, in order to not overflow the
-- integers. Also, not to flood the RAM.
fat :: (Num a, Eq a) => a -> a
fat 0 = 1
fat n = 1 * (fat (n-1))

{-
main :: IO ()
main = do
    print "Start"
    timeIt $ (print (fat 100000))
    print "End"
-}

-- main = secs <$> time_ someIOFunction >>= print
-- main = CM.secs <$> CM.time_ (fat 100000) >>= print

main = defaultMain [
  bgroup "fat" [ bench "1"  $ whnf fat 100000
               , bench "5"  $ whnf fat 100000
               , bench "9"  $ whnf fat 100000
               , bench "11" $ whnf fat 100000
               ]
  ]
