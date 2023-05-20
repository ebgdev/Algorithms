from heapq import heappush, heappop, heapify
from collections import defaultdict

class Node:
    def __init__(self, freq, char):
        self.freq = freq
        self.char = char
        self.left = None
        self.right = None

    def __lt__(self, other):
        return self.freq < other.freq

def build_huffman_tree(text):
    # Count the frequency of each character in the text
    frequency = defaultdict(int)
    for char in text:
        frequency[char] += 1

    # Create a priority queue (min-heap) and push all the nodes into it
    heap = []
    for char, freq in frequency.items():
        node = Node(freq, char)
        heappush(heap, node)

    # Build the Huffman tree
    while len(heap) > 1:
        left = heappop(heap)
        right = heappop(heap)

        # Create a parent node with combined frequency
        parent = Node(left.freq + right.freq, None)
        parent.left = left
        parent.right = right

        heappush(heap, parent)

    # Return the root of the Huffman tree
    return heap[0]

def generate_huffman_codes(root, code, huffman_codes):
    if root is None:
        return

    # Leaf node found, store the Huffman code
    if root.char:
        huffman_codes[root.char] = code

    generate_huffman_codes(root.left, code + '0', huffman_codes)
    generate_huffman_codes(root.right, code + '1', huffman_codes)

def huffman_encode(text):
    huffman_codes = {}
    root = build_huffman_tree(text)
    generate_huffman_codes(root, '', huffman_codes)

    encoded_text = ''
    for char in text:
        encoded_text += huffman_codes[char]

    return encoded_text, huffman_codes

def huffman_decode(encoded_text, huffman_codes):
    decoded_text = ''
    current_code = ''
    for bit in encoded_text:
        current_code += bit
        if current_code in huffman_codes:
            char = huffman_codes[current_code]
            decoded_text += char
            current_code = ''

    return decoded_text

# Example usage
text = "Hello, Huffman coding!"
encoded_text, huffman_codes = huffman_encode(text)
decoded_text = huffman_decode(encoded_text, huffman_codes)

print("Original text:", text)
print("Encoded text:", encoded_text)
print("Decoded text:", decoded_text)
