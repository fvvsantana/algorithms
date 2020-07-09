class KthLargest {
public:
    // Create heap
    priority_queue <int, vector<int>, greater<int> > heap;
    int mK;

    KthLargest(int k, vector<int>& nums) {
        mK = k;
        // Insert numbers, but control for the heap to have maximum size of k
        for(auto it = nums.begin(); it != nums.end(); it++){
            heap.push(move(*it));
            if(heap.size() == mK + 1){
                // 2 3 4 5 8
                // 1 2 3 4 5 8
                // 3 4 4 5 8
                heap.pop();
            }
        }

        // 10:58
    }

    int add(int val) {
        // Insert element
        heap.push(val);

        // Control size
        if(heap.size() == mK + 1){
            heap.pop();
        }

        // Return top
        return heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

/*
Reading: 09:36, 7 min
Solving:
solution 1: 09:43, 12 min
solution 2: 09:55, 14 min
            10:09, end
Coding: 10:43, 17 min
        11:00, end

4 5 8 2


 8 5 4 3 2
 8 5 5 4 3 2
10 8 5 5 4 3 2
10 9 8 5 5 4 3 2
10 9 8 5 5 4 4 3 2

1st solution:
tree (red black)
put nums in the tree O(n log n)
Call c times: O(c * n)
    Add elem in the call O(log n)
    k steps looping through the tree O(k) = O(n)

c = number of calls of add method
Complexity:
Time: O(max(n log n, c * n)) = O(n * max(log n, c))
        Normal case: O(n log n)
Space: O(n)

09:54


2nd solution:
nums[k] <= k-1 numbers in nums
and
nums[k] >= n - k numbers

2 3 4 5 8
min heap, with size k,
put nums in the heap O(n log k) worst, O(n) average
Call c times: O(c * log k) worst, O(c) average
    Add elem in the call O(log k) worst
                        O(1) on average case
    return top O(1)


Complexity:
Time: O(max(n,c))
Space: O(k) without input
        O(n) with input

10:09






*/
