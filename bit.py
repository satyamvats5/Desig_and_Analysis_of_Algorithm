# Implementation of Binary Index Tree to get the sum of elemnts of array in log(n) time commplexity.


def sum(tree, n):
	sum = 0
	n += 1 # n is incremented by 1 as the elements in tree is 1 indexed.
	while(n > 0):
		sum += tree[n]
		n -= (n & ( -n))  #parent of the node is found by substracting last set bit from n.
	return sum

def update(tree, n, i, val):
	i += 1 # i is incremented by 1 because the tree is 1 indexed.
	while i <= n:
		tree[i] += val
		i +=  ( i & (-i)) # parent of the node is found by adding last set bit from i.


def create_b_i_tree(a, n):
	b_tree = [0] * ( n+1 )  #initialising empty tree with zero
	for i in range(n):
		update(b_tree, n, i, a[i]) #ading each element to tree
	print(b_tree)
	return b_tree


a = [2, 1, 1, 3, 3,4, 7, 4, 21, 05, 9]
print("Original array is : ", a)
b_i_t = create_b_i_tree(a, len(a))  # creating binary index tree
n  = int(input("Enter strting index: "))
r = int(input("Enter last index: "))
print(sum(b_i_t, r) - sum(b_i_t, n - 1)) # To get the sum of range of elements of a list sum() function is called twice and the values of sum (1 to r) is substracted by sum(1 to n-1).
update(b_i_t, len(b_i_t),3, 6) #adding 6 to 3rd index element
print(sum(b_i_t, r) - sum(b_i_t, n - 1)) # To get the sum of range of elements of a list sum() function is called twice and the values of sum (1 to r) is substracted by sum(1 to n-1).
print(b_i_t)
