def matrix_identity(n):
    return [[1 if  i==j else 0 for j in range(n)] for i in range(n)]

def transposed(matrix):
    t_matrix = matrix.copy()
    for i in range(len(t_matrix)):
        for j in range(len(t_matrix)):
            if i!=j:
                t_matrix[i][j] = matrix[j][i]
    return t_matrix
    
def mult(M, N):
    new_mx = []
    if len(M[0]) == len(N):
        for line in M:
            new_line = []
            for i in range(len(N[0])):
                new_line.append(sum(line[j]*N[j][i] for j in range(len(line))))
            new_mx.append(new_line)
    return new_mx

def is_orthogonal(mx):
    return mult(mx, transposed(mx))==matrix_identity(len(mx))
