/*
LeetCode – Pain Fence
 
There is a fence with n posts, each post can be painted with one of the k colors. You have to paint all the posts such that two adjacent posts don't have the same color. Return the total number of ways you can paint the fence.
*/

/*
Reading: 10:25 - 10:28
Solving: 10:29 - 10:43


Ex:
k = 3
n = 5
01010
01201
02020
12121
21212

Brute force:
For each solution O(k^n * n)
	Check solution O(n)
Time: O(k^n)
Space: O(n) or O(1)

DP:

S = k*(k-1)^(n-1)

W(1) = k
W(n) = (k-1) * W(n-1)
*/

