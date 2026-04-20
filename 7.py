# Check if it's safe to color this node
def isSafe(node, graph, colors, color, numNodes):
    for neighbor in range(numNodes):
        if graph[node][neighbor] == 1 and colors[neighbor] == color:
            return False
    return True


def solveGraphColoring(node, graph, m, colors, numNodes):
    # All nodes colored
    if node == numNodes:
        return True

    # Try all colors
    for color in range(1, m+1):
        if isSafe(node, graph, colors, color, numNodes):
            colors[node] = color

            if solveGraphColoring(node+1, graph, m, colors, numNodes):
                return True

            # Backtrack
            colors[node] = 0

    return False


# Graph (Adjacency Matrix)
graph = [
    [0,1,1,1],
    [1,0,1,0],
    [1,1,0,1],
    [1,0,1,0]
]

numNodes = 4
m = 3  # number of colors

colors = [0] * numNodes

if solveGraphColoring(0, graph, m, colors, numNodes):
    print("Solution (Node:Color):")
    for i in range(numNodes):
        print(f"{i} -> {colors[i]}")
else:
    print("No solution")