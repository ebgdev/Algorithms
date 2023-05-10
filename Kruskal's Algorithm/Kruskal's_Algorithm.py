class DisjointSet:
    def __init__(self, n):
        self.parent = [i for i in range(n)]
        self.rank = [0] * n

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        root_x, root_y = self.find(x), self.find(y)
        if root_x == root_y:
            return False
        if self.rank[root_x] < self.rank[root_y]:
            self.parent[root_x] = root_y
        elif self.rank[root_x] > self.rank[root_y]:
            self.parent[root_y] = root_x
        else:
            self.parent[root_y] = root_x
            self.rank[root_x] += 1
        return True


def kruskal(n, edges):
    dsu = DisjointSet(n)
    mst = []
    edges.sort(key=lambda x: x[2])
    for edge in edges:
        u, v, w = edge
        if dsu.union(u, v):
            mst.append(edge)
    return mst


n = 5
edges = [(0, 1, 2), (0, 3, 6), (1, 3, 8), (1, 4, 5), (1, 2, 3), (2, 4, 7), (3, 4, 9)]
mst = kruskal(n, edges)
print(mst)
