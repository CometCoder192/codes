def find(p, x):
    if p[x] != x:
        p[x] = find(p, p[x])
    return p[x]

def kruskal(n, edges):
    p = list(range(n))
    mst, total = [], 0

    for u, v, w in sorted(edges, key=lambda x: x[2]):
        pu, pv = find(p, u), find(p, v)
        if pu != pv:
            p[pu] = pv
            mst.append((u, v, w))
            total += w

    return mst, total


edges = [(0,1,10),(0,2,6),(0,3,5),(1,3,15),(2,3,4)]

mst, total = kruskal(4, edges)

print("MST:", mst)
print("Total:", total)