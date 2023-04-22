def searchBinary(myList,item):

	first = 0 
	last = len(myList)-1 
	foundFlag = False 

	while( first<=last and not foundFlag):

		mid = (first + last)//2

		if myList[mid] == item :

			foundFlag = True

		else:

			if item < myList[mid]: last = mid - 1

			else:

				first = mid + 1 
	return foundFlag




result = searchBinary([900,780,600,433,344,150,80,23,1], 99)

print(result)