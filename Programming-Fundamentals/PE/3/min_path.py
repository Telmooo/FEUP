def min_path(matrix, a, b, visited=[], steps = 0):
    x0, y0 = a
    x1, y1 = b
    minx = 10**100 #infinity
    if x0 == x1 and y0==y1: return steps
    vis = visited.copy()

    vis.append(a)

    for i in range(-1, 2):
        for j in range(-1, 2):
            x = x0+i
            y = y0+j
            if in_bounds(matrix, x, y):
                if not matrix[x][y]:
                    if (x, y) not in vis:
                        x = min_path(matrix, (x, y), b, vis, steps+1)
                        if x<minx:
                            minx=x
    return minx

def in_bounds(matrix, x, y):
    row = len(matrix)-1
    cols = len(matrix[0])-1
    return 0<=x<=row and 0<=y<=cols
