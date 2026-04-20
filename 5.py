import heapq

maze = [
    [0,0,0,0,0],
    [1,1,1,1,0],
    [1,1,1,1,0],
    [1,1,1,1,0],
    [1,1,1,1,0]
]

maxRow, maxCol = 5, 5
start = (0,0)
goal = (4,4)

# Heuristic function (Manhattan distance)
def heuristic(currentPos, goalPos):
    return abs(currentPos[0] - goalPos[0]) + abs(currentPos[1] - goalPos[1])

def aStar(maze):
    priorityQueue = []
    
    # (fCost, gCost, position, path)
    heapq.heappush(priorityQueue, (0, 0, start, [start]))

    visited = set()

    directions = [(-1,0),(1,0),(0,-1),(0,1)]

    while priorityQueue:
        fCost, gCost, currentPos, path = heapq.heappop(priorityQueue)

        if currentPos in visited:
            continue
        visited.add(currentPos)

        if currentPos == goal:
            return path

        currentRow, currentCol = currentPos

        for dRow, dCol in directions:
            newRow, newCol = currentRow + dRow, currentCol + dCol
            newPos = (newRow, newCol)

            if (0 <= newRow < maxRow and
                0 <= newCol < maxCol and
                maze[newRow][newCol] == 0):

                newGCost = gCost + 1
                newFCost = newGCost + heuristic(newPos, goal)

                heapq.heappush(priorityQueue, 
                    (newFCost, newGCost, newPos, path + [newPos]))

    return None


# Run
path = aStar(maze)

print("A* Path:")
print(path)
print("Steps:", len(path) - 1 if path else "No path found")