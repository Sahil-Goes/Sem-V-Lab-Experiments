#Best First Search
#DFS Goal Search
graph = {
    'A': [('B',12), ('C',4)],
    'B': [('D',7) , ('E',3)],
    'C': [('F',8) , ('G',2)],
    'D':[],
    'E':[('H',0)],
    'F':[('H',0)],
    'G':[('H',0)],
    'H':[]
}

def best_first_search(graph, start, goal, open=[], close=[]):
    if start not in close:
        print(start)
    close.append(start)

    for x in graph[start]:
        if x[0] not in [node[0] for node in open]:
            open.append(x)

    open.sort(key= lambda x:x[1])

    if open[0][0] == goal:
        print(open[0][0])
    else:
        node = open[0]
        open.remove(node)
        best_first_search(graph, node[0], goal, open, close)

start = input("Enter start node: ")
goal = input("Enter goal node: ")
best_first_search(graph, start, goal)