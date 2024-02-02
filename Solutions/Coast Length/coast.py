# =================================================================================
#                             Iterative BFS (Accepted)
# =================================================================================

n, m = map(int, input().split())
grid = [[int(i) for i in list(input())] for _ in range(n)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs(i, j):
    queue = [(i, j)]
    while queue:
        x, y = queue.pop(0)
        grid[x][y] = 2 
        for k in range(4):
            new_x, new_y = x + dx[k], y + dy[k]
            if 0 <= new_x < n and 0 <= new_y < m and grid[new_x][new_y] == 0:
                queue.append((new_x, new_y))
                grid[new_x][new_y] = 2

for i in range(n):
    for j in range(m):
        if grid[i][j] == 0 and (i == 0 or i == n-1 or j == 0 or j == m-1):
            bfs(i, j)

count = 0
for i in range(n):
    for j in range(m):
        if grid[i][j] == 1:
            if i + 1 >= n or grid[i+1][j] == 2:
                count += 1
            if i - 1 < 0 or grid[i-1][j] == 2:
                count += 1
            if j + 1 >= m or grid[i][j+1] == 2:
                count += 1
            if j - 1 < 0 or grid[i][j-1] == 2:
                count += 1

print(count)



# =================================================================================
#     Recursive DFS (Fails on test 14: Runtime Error (Recusion Depth Exceeded?))
# =================================================================================
'''

 n, m = map(int, input().split())
grid = [[int(i) for i in list(input())] for _ in range(n)]

def dfs(i, j):
    if i < 0 or i >= n or j < 0 or j >= m or grid[i][j] == 2 or grid[i][j] == 1:
        return
    grid[i][j] = 2
    dfs(i+1, j)
    dfs(i-1, j)
    dfs(i, j+1)
    dfs(i, j-1)

for i in range(n):
    for j in range(m):
        if grid[i][j] == 0 and (i == 0 or i == n-1 or j == 0 or j == m-1): 
            dfs(i, j)

count = 0
for i in range(n):
    for j in range(m):
        if grid[i][j] == 1:
            if i + 1 >= n or grid[i+1][j] == 2: 
                count += 1
            if i - 1 < 0 or grid[i-1][j] == 2:
                count += 1
            if j + 1 >= m or grid[i][j+1] == 2:
                count += 1
            if j - 1 < 0 or grid[i][j-1] == 2:
                count += 1
            
print(count)

'''