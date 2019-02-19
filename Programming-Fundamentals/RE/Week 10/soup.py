"""
Crazy letter soup
"""
def get_neighbours(matrix, x, y):
    def in_matrix(matrix, x, y):
        r, c = len(matrix)-1, len(matrix[0])-1
        if not (0<=x<=r and 0<=y<=c):
            return False
        return True

    neighbours = []
    positions = []
    for i in range(-1, 2):
        for j in range(-1, 2):
            if i==0 and j==0:
                continue
            if in_matrix(matrix, x+i, y+j):
                neighbours.append(matrix[x+i][y+j])
                positions.append((x+i, y+j))
    return neighbours, positions

def soup(matrix, word):
    def form_word(matrix, xi, yi, word):
        if len(word) == 1:
            return True
        neighbourhood, positions = get_neighbours(matrix, xi, yi)
        for i, n in enumerate(neighbourhood):
            if word[0]==n:
               x1, x2 =  positions[i]
               if form_word(matrix, x1, x2, word[1:]):
                   return True
        return False
        

    for idxl, line in enumerate(matrix):
        for idxc, obj in enumerate(line):
            if word[0]==obj:
                out = f"{chr(idxl+65)}{idxc+1}"
                if form_word(matrix, idxl, idxc, word[1:]):
                    return out
    return
