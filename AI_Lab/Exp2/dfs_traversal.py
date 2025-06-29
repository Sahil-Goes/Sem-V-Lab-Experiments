#BFS Traversal
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
        while open:
            node = open.pop()
            if node not in close:
                close.append(node)
                neighbours = graph[node]
                for i in neighbours:
                    open.append(i)
        return close

start = input("Enter start node: ")
print("BFS Traversal: ", bfs(graph))