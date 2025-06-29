#BFS Search
graph = {
    'A': ['B','C'],
    'B': ['D'],
    'C': ['E'],
    'D': ['F'],
    'E': ['F'],
    'F': []
}


def bfs(graph):
        close =[]
        open = [start]
        if start == goal:
            print ("Start node is goal node!")
            return
        
        close.append(start)
        while open:
            node = open.pop(0)
            for neighbour in graph[node]:
                if neighbour not in close:
                    close.append(neighbour)
                    open.append(neighbour)
                    if neighbour == goal:
                        print("Goal Found!")
                        return close
        return "Sorry a connecting path doesn't exist!"

start = input("Enter start node: ")
goal = input("Enter goal node: ")
print("BFS Traversal: ", bfs(graph))