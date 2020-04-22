## Priority Queue
#### Types: 
##### 1. Ascending PQ (pop minimum)
##### 1. Descending PQ (pop maximum) 

#### Application:
##### Data compression, shortest path algorithms, MST algorithms, Event-Driven simulation, Selection Problem 

#### Complexity 
###### Unordered array/ list - Insertion O(1), Deletion O(n), Search O(n)
###### Ordered array/ list - Insertion O(n), Deletion O(1), Search O(1)
###### Balanced BST - O(longN) for all
###### Binary Heap - O(longN) for I, D and O(1) for search 

### Types of Heap
#### 1. Min Heap
The value of a node must be less than or equal to the values of its children 
#### 1. Max Heap
The value of a node must be greater than or equal to the values of its children 

###### Representing Heaps-
One possibility is using arrays. Since heaps are forming complete binary trees, there will not be any wastage of locations <br>
For a node at ith location, its parent is at (i-1)/2  <br>
Similarly For a node at ith location, its children are at (2 * i + 1) and (2 * i + 2) <br>

###### Heapifying an Element -
After inserting an element into heap, it may not satisfy the heap property. In that case we need to adjust the locations of the heap
to make it heap again. This process is called heapifying. In maxheap, to heapify an element, we have to find the maximum of its children
and swap it with the current element and continue this process until the heap property is satisfied at every node. (PercolateDown)<br>
To heapify, find the maximum of its children and swap with that. <br>
<b> One important property of heap is that, if an element is not satisfying the heap
property, then all the elements from that element to the root will have the same problem. </b>
  
###### Deleting an Element
To delete an element from heap, we just need to delete the element from the root. This is the only
operation (maximum element) supported by standard heap. After deleting the root element, copy
the last element of the heap (tree) and delete that last element. <br>
After replacing the last element, the tree may not satisfy the heap property. To make it heap again,
call the PercolateDown function. (PrelocateUp for inserting)

### Note:
each call to Heapify costs O(logn) and Build-Heap makes O(n) such calls.
