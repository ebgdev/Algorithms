# Author : Erfan Baghchehdan
# Email : ebgdev@proton.me

===========================================================

The bubble_sort function takes an array arr and its length n as input arguments.

The function uses two nested loops to iterate over the array elements.

The outer loop runs from i=0 to n-1, and the inner loop runs from j=0 to n-i-1.

In each iteration of the inner loop, the function compares the adjacent elements arr[j] and arr[j+1]. If arr[j] is greater than arr[j+1], the function swaps their positions.

After completing the inner loop, the largest element in the unsorted part of the array is moved to the end of the array.

The function repeats this process until the entire array is sorted.

In the main function, we create an example array arr and pass it to the bubble_sort function. We then print the sorted array to the console.
