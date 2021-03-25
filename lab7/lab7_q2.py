'''
Write Python code to find the cost of the minimum-energy seam in a list of lists.

energies = [[24,      22,      30,      15,      18,      19],
            [12,      23,      15,      23,      10,     15],
            [11,      13,      22,      13,      21,      14],
            [13,      15,      17,      28,      19,      21],
            [17,      17,      7,       27,      20,      19]]
     
    The correct output for the given energies data is 15+10+13+17+7 = 62.

'''
def find_cost(L):
    res_L = []
    min = L[0][0]
    index = -1
    for i in range(len(L[1])):
        if L[0][i] < min:
            min = L[0][i]
            index = i
    res_L.append(min)

    for i in range(1, len(L)):
        min = L[i][index - 1]
        index_m = index
        for j in range (index_m -1, index_m + 2):
            #print(index + j)
            #print(L[i][index + j])
            if L[i][j] < min:
                min = L[i][j]
            index_m = L[i].index(min)
            #print(index_m)
        res_L.append(min)

    print(res_L)
    res = 0
    for k in res_L:
        res += k

    return res
                

        




#to test:
L = [[24,      22,      30,      15,      18,      19],
    [12,      23,      15,      23,      10,     15],
    [11,      13,      22,      13,      21,      14],
    [13,      15,      17,      28,      19,      21],
    [17,      17,      7,       27,      20,      19]]

min_cost = find_cost(L)
print(min_cost)