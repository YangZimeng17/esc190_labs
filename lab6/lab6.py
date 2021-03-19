
# Lab 6

#
# We'll define a node of a binary tree and introduce some features of Python
# classes along the way


class BST:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

    def insert(self, value):
        '''
        node.insert(5) is the same as BST.insert(node, 5)
        We use this when recursively calling, e.g. self.left.insert
        '''
        if value < self.value:
            if self.left == None:
                self.left = BST(value)
            else:
                self.left.insert(value)
        else:
            if self.right == None:
                self.right = BST(value)
            else:
                self.right.insert(value)

    def __repr__(self):
        '''The string representation of a node.
        Here, we convert the value of the node to a string and make that
        the representation.
        We can now use
        a = Node(4)
        print(a) # prints 4
        '''
        return str(self.value)



a = BST(4)
a.insert(2)
a.insert(5)
a.insert(10)
a.insert(3)
a.insert(15)

# Problem 1
# Draw (manually) the binary tree rooted in a.
#
#          |4|        
#    |2|        |5|
#       |3|         |10| 
#                        |15|
#

# Problem 2
# Write code to find the height of a Binary Search Tree
def find_height(node):
    if node == None:
        return 0
    else:
        left_H = find_height(node.left)
        right_H = find_height(node.right)

        if (left_H > right_H):
            return left_H + 1
        else:
            return right_H + 1

print(find_height(a)) # did return 4 (correct)

# Problem 3

# Write code to print out the nodes of the BST using
# Breadth-First Search. How would you get the Breadth-First Traversal
# from the tree you've drawn?
# (Modify the BFS function from lecture for this problem)

def BFS_tree(node):
    height = find_height(node)
    for i in range(1, height + 1):
        print_level(node, i)

def print_level(node, level):
    if node == None:
        return
    if level == 1:
        print(node.value)
    elif level > 1:
        print_level(node.left, level - 1)
        print_level(node.right, level - 1)

BFS_tree(a)

# The BF traversal of a tree prints nodes level-by-level

# Problem 4

# Empirically investigate the relationship between the number of nodes in the
# tree and the height of the tree when inserting nodes with values generated
# using random.random()

import random


def make_random_tree(n_nodes):
    '''Make a tree with n_nodes nodes by inserting nodes with values
    drawn using random.random()
    '''
    t=BST(random.random())
    for i in range(n_nodes-1):
        t.insert(random.random())
        
    return t

'''        
t1=make_random_tree(5)
BFS_tree(t1)
'''


def height_random_tree(n_nodes):
    '''Generate a random tree with n_nodes nodes, and return its height'''
    tr=make_random_tree(n_nodes)
    #BFS_tree(tr)
    return BST_height(tr, h=0)

'''
h1=height_random_tree(9)
print(h1)
'''


def make_data(max_nodes):
    '''Make two lists representing the empirical relationship between
    the number of nodes in a random tree and the height of the tree.
    Generate N_TREES = 40 trees with each of
    n_nodes = 5, int(1.2*5), int(1.2^2*5), .....

    return n (a list of values of n_nodes) and h (a list of heights)

    '''
    N_TREES = 40
    n_nodes = 5
    n=[]  # a list of values of n_nodes
    h=[]  # a list of heights
    n.append(n_nodes)
    h.append(height_random_tree(n_nodes))
    for i in range(1,N_TREES):
        n_nodes*=1.2
        n_nodes=int(n_nodes)
        n.append(n_nodes)
        h.append(height_random_tree(n_nodes))

    return n, h

n, h = make_data(10000)
print(n)
print(h)
'''
for i in range(len(n)):
    print(str(n[i]) +"     "+ str(h[i]))
'''

n, h = make_data(10000)
import matplotlib.pyplot as plt
plt.scatter(n, h)
plt.show()
# plt.savefig("trees.png") can save the data to disk
