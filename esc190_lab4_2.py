"""
write a function find(L, e) that takes in a sorted list L and an element e, and returns the lowest index in L such that L[i] == e. (-1 if there is no such index)
   Write a function that takes in a sorted list L and an element e, and returns the index of the highest index in L such that L[i] == e. (-1 if there is no such index).
"""

def find_lowest(L, e):
    try:
        index = L.index("e")
        
    except ValueError:
        return -1
    
    return index

def find_highest(L, e):
    L = list(reversed(L))
    try:
        index = L.index("e")
        
    except ValueError:
        return -1
    
    return index

L1 = ['a', 'e', 'i', 'o', 'i', 'u']
print(find_lowest(L1, "e"))
print(find_lowest(L1, "h"))

L2 = []
print(find_lowest(L2, "e"))
print(find_lowest(L2, ""))

print(find_highest(L1, "e"))
print(find_highest(L1, "h"))