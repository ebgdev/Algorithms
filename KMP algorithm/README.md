# Breadth-First Search

# Author : Erfan Baghchehdan Ghadimi

# Email : ebgdev@proton.me

=========================================================

In this implementation, the computeLPSArray() function is used to calculate the Longest Proper Prefix which is also a Suffix (LPS) array for the pattern. The LPS array is used to avoid unnecessary comparisons when searching for the pattern in the text.

The kmpSearch() function is then used to perform the actual search for the pattern in the text using the LPS array. It iterates through each character in the text, comparing it to the corresponding character in the pattern. If a match is found, it advances both the text and pattern indices. If the pattern is found, it prints the index of the first character of the pattern in the text. If the pattern is not found, the indices are adjusted according to the LPS array.

In the main() function, the kmpSearch() function is called with a sample text and pattern for demonstration purposes. You can modify this code to use your own input text and pattern.