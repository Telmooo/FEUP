"""
Auxiliar functions
"""
#------------------------------------------------------------------------------------------------
#Called to turn everything pretty uhu :)
def reshape(ls, rows, cols):
    """Reshape a list into a matrix with dimensions given"""
    return [ls[i*cols:(i+1)*cols] for i in range(rows)]

#------------------------------------------------------------------------------------------------
#Called to remove the junk from our board
def filter_board(matrix):
    """Remove the coordinates from the board"""
    return [x[0] for x in matrix]

#------------------------------------------------------------------------------------------------
#Called to check if the input location is on the matrix range
def in_bounds(matrix, row, col):
    """Checks if given position is still in bounds of the matrix"""
    maxRow, maxCol = len(matrix)-1, len(matrix[0])-1
    return (0 <= row <= maxRow and 0 <= col <= maxCol)

#------------------------------------------------------------------------------------------------
#Called to get all adjacents tiles of the tile with input location on the input matrix
def get_adjacents(matrix, row, col):
    """Get adjacent tiles of a given tile"""
    adjacents = []
    #get all possible locations for adjacents blocks
    for i in range(-1, 2):
        for j in range(-1, 2):
            if i == 0 and j == 0:
                #if the tile is himself it doesn't exist, it does, but yeah :)
                continue
            elif in_bounds(matrix, row+i, col+j):
                adjacents.append(matrix[row+i][col+j])
            else:
                #if it's not on the matrix range
                continue

    return adjacents

#------------------------------------------------------------------------------------------------
#print matrix
def print_grid(matrix):
    cols = len(matrix[0])
    out = []
    #format the matrix to be kinda pretty
    out.append("-"*(4*cols+1))
    for row in matrix:
        row_line = " | ".join(str(value) if value!=-1 else " " for value in row)
        out.append("| " + row_line + " |")
        out.append("-"*(4*cols+1))
    print("\n".join(out))
