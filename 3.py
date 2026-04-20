def dfsWaterJug(capA, capB, target):
    visited = set()
    path = []

    def dfs(a, b):
        # If already visited → skip
        if (a, b) in visited:
            return False

        visited.add((a, b))
        path.append((a, b))

        # Goal check
        if a == target or b == target:
            return True

        # All possible moves
        nextStates = [
            (capA, b),  # fill A
            (a, capB),  # fill B
            (0, b),     # empty A
            (a, 0),     # empty B

            # pour A → B
            (a - min(a, capB - b), b + min(a, capB - b)),

            # pour B → A
            (a + min(b, capA - a), b - min(b, capA - a))
        ]

        for nextA, nextB in nextStates:
            if dfs(nextA, nextB):
                return True

        # Backtrack
        path.pop()
        return False

    dfs(0, 0)
    return path


# Example
result = dfsWaterJug(4, 3, 2)

print("Steps:")
for step in result:
    print(step)