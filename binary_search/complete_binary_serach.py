import math
array = [1,2,3,4,5,6,7,8]
x = 13

def firstMid(array,x):

	length = len(array)
	half = int(len(array)/2)

	lside = half-1
	rside = half
	# mid is the index of mid element
	if length %2 != 0:
		mid = array[round(length/2)]
	else:
		mid = lside if abs(x-lside)< abs(x-rside) else rside
	return mid

def binarySearch(array,x):
	very_left = left = 0
	very_right = right = len(array) -1
	mid = firstMid(array,x)
	condition = True 

	while condition:
		if x == array[mid]:
			condition = False
			return f"The x index is :{mid}"
		elif very_left == mid or very_right == mid:
			condition = False
			return "Not Found!"
		elif x > array[mid]:
			left = mid
			mid = math.ceil((left + right)/2)
		elif x < array[mid]:
			right = mid
			mid = math.ceil((left + right)/2)
		


print(binarySearch(array,x))