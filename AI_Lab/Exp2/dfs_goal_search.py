#DFS Goal Search
tree = {
    'A': ['B','C'],
    'B': ['D','E'],
    'C': ['F','G'],
    'D': [],
    'E': [],
    'F': [],
    'G': []
}


def dfs(tree):
        close =[]
        open = [start]
        if start == goal:
            print("Start node is goal node!")
            return
        
        while open:
            node = open.pop()
            if node not in close:
                close.append(node)
                neighbours = tree[node]
                for i in neighbours:
                    open.append(i)
                    if i == goal:
                        close.append(i)
                        print("Goal node found!")
                        return close
        return "Sorry, Goal node not found!"

start = input("Enter start node: ")
goal = input("Enter goal node: ")
print("DFS Goal Search: ", dfs(tree))