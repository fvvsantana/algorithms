/*
LeetCode – Pain Fence
 
There is a fence with n posts, each post can be painted with one of the k colors. You have to paint all the posts such that no more than two adjacent fence posts have the same color. Return the total number of ways you can paint the fence.
*/

/*
Reading: 10:55 - 10:57
Solving: 10:58

k = 3
n = 5
01010
00100
33100
12345
BF:
For each possible solution O(k^n * n)
	Check solution O(n)

k 1
if both match
k-1
1
if both match
k-1
k

k k-1


11:04
DP:
m belongs to {0,1}

W(0, w) = 1 

if m == 1:
	W(i, m) = (k-1) * W(i-1, 0)
else # m == 0
		    match	    don't match
	W(i, m) = 1 * W(i-1, 1) + (k-1) * W(i-1, 0)

Matrix= (n+1) x 2

11:19

Total time up to here with no coding:
11:19 - 10:55 = 24 minutes

*/

