import numpy as np

class Node:
    def __init__(self, name):
        self.name = name
        self.connections = []
        self.visited = False


def connect(node1, node2, weight):
    node1.connections.append({"node": node2, "weight": weight}) #gives a list of dictionaries
    #print(node1.connections)
    node2.connections.append({"node": node1, "weight": weight})


def BFS(node):
    q = [node]
    node.visited = True
    while len(q) > 0:
        cur = q.pop(0) # remove q[0] from q and put it in cur
        print(cur.name)
        for con in cur.connections:
            if not con["node"].visited:
                q.append(con["node"]) #add this node to queue q
                con["node"].visited = True

################################################################################

def get_all_nodes(node):
    '''Return a list of the nodes in the graph of nodes connected to node
    (N.B., the nodes can be indirectly connected as well, like the one that connects with 
    the node of the node, the node of the node of the node etc.)'''
    q = [node]
    res = []
    node.visited = True
    while len(q) > 0:
        cur = q.pop(0) # remove q[0] from q and put it in cur
        res.append(cur)
        for con in cur.connections:
            if not con["node"].visited:
                q.append(con["node"]) #add this node to queue q
                con["node"].visited = True

    return res

################################################################################

def unvisit_all(node):
    '''Change all n.visited to False in all the nodes in the graph of nodes
    connected to node. Use BFS to find all the nodes'''
    q = [node]
    node.visited = False
    while len(q) > 0:
        cur = q.pop() # remove q[0] from q and put it in cur
        #print(cur.name)
        for con in cur.connections:
            if con['node'].visited:
                q.append(con["node"]) #add this node to queue q
                con["node"].visited = False

###############################################################################

def DFS_rec(node):
    '''Print out the names of all nodes connected to node using a
    recursive version of DFS'''
    node.visited = True
    print(node.name)
    for e in node.connections:
        if e['node'].visited == False:
            DFS_rec(e['node'])
    

################################################################################

def DFS_nonrec(node):
    '''Print out the names of all nodes connected to node using a non-recursive
    version of DFS. Make it so that the nodes are printed in the same order
    as in DFS_rec'''
    q = [node]
    while len(q) > 0:
        cur = q.pop()
        if cur.visited == False:
            print(cur.name)
        cur.visited = True
        for e in cur.connections:
            if e['node'].visited == False:
                q.append(cur)
                q.append(e['node'])
                break



################################################################################
#
# OPTIONAL
#

def dijsktra_slowish(node):
    '''Implement Dijkstra's algorithm as discussed in class (i.e., you don't
    need to use a priority queue'''
    S = [node]
    d = {node.name: 0}

    unexplored = get_all_nodes(node)
    unexplored.remove(node)

    while len(unexplored) > 0:
        # your code here
        pass

    return d



if __name__ == '__main__':
    TO = Node("TO")
    NYC = Node("NYC")
    DC = Node("DC")
    CDMX = Node("CDMX")
    SF = Node("SF")

    connect(TO, NYC, 3)
    connect(TO, SF, 6)
    connect(TO, CDMX, 7)
    connect(NYC, DC, 2)
    connect(SF, DC, 5)

    #L = get_all_nodes(TO)
    #BFS(TO)
    #DFS_rec(TO)
    DFS_nonrec(TO)
    unvisit_all(TO)
    #DFS(TO)
    #print(dijsktra_slowish(TO))