class RouteNode:
    def __init__(self, src, dest, dist, time, cost):
        self.src = src
        self.dest = dest
        self.dist = dist
        self.time = time
        self.cost = cost
        self.left = None
        self.right = None


class RouteBST:
    def __init__(self):
        self.root = None

    # Insert based on distance (can change to time/cost)
    def insert(self, root, node):
        if root is None:
            return node
        if node.dist < root.dist:
            root.left = self.insert(root.left, node)
        else:
            root.right = self.insert(root.right, node)
        return root

    # Inorder → sorted routes
    def inorder(self, root):
        if root:
            self.inorder(root.left)
            print(root.src, "->", root.dest, "| Dist:", root.dist)
            self.inorder(root.right)

    # Find best (minimum distance)
    def findBest(self, root):
        while root.left:
            root = root.left
        return root

    # Update route (by source-destination)
    def update(self, root, src, dest, newDist):
        if root is None:
            return
        if root.src == src and root.dest == dest:
            root.dist = newDist
        self.update(root.left, src, dest, newDist)
        self.update(root.right, src, dest, newDist)


# Usage
bst = RouteBST()

routes = [
    ("A","B",10,30,100),
    ("A","C",5,20,80),
    ("B","C",15,40,120)
]

for r in routes:
    bst.root = bst.insert(bst.root, RouteNode(*r))

print("All routes (sorted by distance):")
bst.inorder(bst.root)

best = bst.findBest(bst.root)
print("\nBest route (shortest distance):", best.src, "->", best.dest, best.dist)