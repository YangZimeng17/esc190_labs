"""
write a function find(L, e) that takes in a sorted list L and an element e, 
and returns the lowest index in L such that L[i] == e. (-1 if there is no such index)
   Write a function that takes in a sorted list L and an element e, and returns 
   the index of the highest index in L such that L[i] == e. (-1 if there is no such index).

    the function should run in O(log(n)) time
"""
def bisect_search_helper(L, e, low, high):
    if high==low:
        if L[high]==e:
            return high
        else:
            return -1
    mid=(low+high)//2
    if L[mid]==e: 
        return mid
    elif L[mid]>e:
        if low==mid:   #nothing left to search
            return -1
        else:
            return bisect_search_helper(L, e, low, mid-1)
    else:
        return bisect_search_helper(L, e, mid+1, high)
    
    
def find_lowest(L, e):
    if len(L)==0:
        return -1
    else:        
        index = bisect_search_helper(L, e, 0, len(L)-1)
        #lines below to make sure to find the lowest when having duplicates

        while True:
            tmp = index-1
            if L[tmp] != e:
                break
            index = bisect_search_helper(L, e, 0, index)

                '''
        while (L[tmp]==e): #cases like L = ['a', 'b', 'a', 'o', 'u'] wouldn't cause problem by unable to check the first elem bc we code under the assumption that it's a sorted list, so same elem has to be beside each other
# worst case is when your elem is at the end
            index=tmp
            tmp-=1
        '''
    return index


def find_highest(L, e):
    if len(L)==0:
        return -1
    else:        
        index = bisect_search_helper(L, e, 0, len(L)-1)
        
        #lines below to make sure to find the highest when having duplicates
        tmp = index+1
        while (L[tmp]==e):
            index=tmp
            tmp+=1
        
    return index

# list need to be sorted
L1 = ['a', 'e', 'i', 'o', 'u']
print(find_lowest(L1, "o"))
print(find_lowest(L1, "h"))

L2 = []
print(find_lowest(L2, "e"))
print(find_lowest(L2, ""))

print(find_highest(L1, "e"))
print(find_highest(L1, "h"))

L3 = ['a', 'e', 'e', 'e', 'i']
print(find_lowest(L3, 'e'))
print(find_highest(L3, 'e'))

"""
# don't have a runtime complexity of log n
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
"""