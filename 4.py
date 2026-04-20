# DFS using any game
from collections import deque

maze = [
    [0,0,0,0,0],
    [1,1,1,1,0],
    [1,1,1,1,0],
    [1,1,1,1,0],
    [1,1,1,1,0]
]

maxRow, maxCol = 5, 5
start = (0,0)
finish = (4,4)

def bfs(maze):
    queue = deque()
    queue.append((start, [start]))

    visited = set()
    visited.add((0,0))

    directions = [(-1, 0), (1,0), (0, -1), (0,1)]

    while queue:
        currPos, path = queue.popleft()
        currRow, currCol = currPos

        if currPos == finish:
            return path

        for delRow, delCol in directions:
            newRow, newCol = currRow + delRow, currCol + delCol
            newPos = (newRow, newCol)
            if (0 <= newRow < maxRow and 0<= newCol < maxCol and maze[newRow][newCol] == 0 and newPos not in visited):
                
                visited.add(newPos)
                queue.append((newPos, path + [(newPos)]))

    return None

path = bfs(maze)

print("Shortest Path: ")
print(path)
print("Steps: ", len(path) - 1 if path else "No Path found.")