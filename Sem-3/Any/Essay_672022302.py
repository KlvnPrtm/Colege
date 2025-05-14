from collections import deque

def find_shortest_path(maze, start, end):
    
    def get_valid_neighbors(node):
        x, y = node
        neighbors = [(x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)]
        valid_neighbors = []
        for neighbor in neighbors:
            nx, ny = neighbor
            if 0 <= nx < len(maze) and 0 <= ny < len(maze[0]) and maze[nx][ny] == '.':
                valid_neighbors.append(neighbor)
        return valid_neighbors

    visited = set()
    queue = deque()
    parent = {}

    queue.append(start)
    visited.add(start)
    found = False

    while queue:
        node = queue.popleft()

        if node == end:
            found = True
            break

        for neighbor in get_valid_neighbors(node):
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)
                parent[neighbor] = node

    if found:
        path = []
        current = end
        while current != start:
            path.append(current)
            current = parent[current]
        path.append(start)
        path.reverse()
        return path
    else:
        return []
    
maze = [
        ['.', '.', '.', 'X', 'X'],
        ['.', 'X', '.', '.', '.'],
        ['.', 'X', 'X', 'X', '.'],
        ['.', '.', '.', '.', '.'],
        ['X', 'X', 'X', 'X', '.'],
        ['.', '.', '.', '.', '.']
    ]
    
try:
    start_input = input("Masukkan koordinat x dan y dari titik awal dalam format (x, y): ") 
    start = eval(start_input)
    end_input = input("Masukkan koordinat x dan y dari titik tujuan dalam format (x, y): ") 
    end = eval(end_input) 
except:
    print("Input tidak valid. Harap masukkan koordinat dalam format (x, y) dengan x dan y adalah bilangan bulat.")
    exit()

shortest_path = find_shortest_path(maze, start, end)

if shortest_path:
    print("Jalur terpendek: ")
    for node in shortest_path:
        print(node)

# Fitur 2: Menandai jalur yang ditemukan dalam labirin dengan karakter khusus
# Menggunakan loop for untuk mengganti sel labirin yang sesuai dengan jalur dengan karakter '*'
# Mengganti sel labirin yang sesuai dengan titik awal dengan karakter 'S'
# Mengganti sel labirin yang sesuai dengan titik tujuan dengan karakter 'E'
    for node in shortest_path:
        x, y = node
        maze[x][y] = '*'

    maze[start[0]][start[1]] = 'S'
    maze[end[0]][end[1]] = 'E'

# Mencetak labirin yang sudah ditandai dengan jalur
    print("Labirin dengan jalur:")
    for row in maze:
        print(row)

else:
    print("Tidak ada jalur yang ditemukan.")

