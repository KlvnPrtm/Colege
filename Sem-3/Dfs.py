# # Contoh graf angka
graph1 = {
    1 : [2,3],
    2 : [1,5],
    3 : [1,4],
    4 : [3,11],
    5 : [2,6],
    6 : [5,7,11],
    7 : [6,8],
    8 : [7,9],
    9 : [8,10,11],
    10 : [9,11],
    11 : [4,6,9,10],
}

def dfs(graph1, node, visited):
    if node not in visited:
        visited.append(node)
        for n in graph1[node]:
            dfs(graph1, n, visited)
    return visited

visited = dfs(graph1,4, [])
print(visited)

# Contoh graf huruf

# graph1 = {
#     A : [B,C],
#     B : [D,E],
#     C : [F,G],
#     D : [H],
#     E : [I],
#     F : [C],
#     G : [J,K],
#     H : [D],
#     I : [E],
#     J : [G],
#     K : [L],
#     L : [K],
# }

# def dfs(graph1, node, visited):
#     if node not in visited:
#         # print(node)
#         visited.append(node)
#         for n in graph1[node]:
#             dfs(graph1, n, visited)
#     return visited

# visited = dfs(graph1,A, [])
# print(visited)