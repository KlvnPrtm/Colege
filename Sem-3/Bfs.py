# Cara 1
graphs = {
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

def bfs(graphs, start):
  visitedList = []
  queue = [start]
  
  while queue:
    current = queue.pop(0)
    
    if current not in visitedList:
      visitedList.append(current)
      neighbor = graphs[current]
      for x in neighbor:
        queue.append(x)
  return visitedList

print(bfs(graphs, 9))

# Cara 2
# membuat daftar node (vertex list)
# vertexList = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]
# edgeList = [
#              (1,2), (1,3), (2,1), 
#              (2,5), (3,1), (3,4), 
#              (4,3), (4,11), (5,2), 
#              (5,6), (6,5), (6,7), 
#              (6,11), (7,6), (7,8), 
#              (8,7), (8,9), (9,8), 
#              (9,10), (9,11), (10,9), 
#              (10,11), (11,4), (11,6), 
#              (11,9), (11,10)
#              ]

# graphs = vertexList, edgeList

# def bfs(graphs, start):
#     vertexList, edgeList = graphs
#     visitedList = []
#     queue = [start]
#     adjacencyList = [[] for vertex in vertexList]
#     # print(adjacencyList)

#     # fill adjacencyList from graph
#     for edge in edgeList:
#         # print(edge)
#         adjacencyList[edge[0]-1].append(edge[1]-1)

#         # print("adjacent : ",adjacencyList)
#     # bfs
#     while queue:
#         current = queue.pop()
#         for neighbor in adjacencyList[current]:
#             if not neighbor in visitedList:
#                 queue.insert(0,neighbor)
#         visitedList.append(current)
#     return visitedList

# print(bfs(graphs, 9))