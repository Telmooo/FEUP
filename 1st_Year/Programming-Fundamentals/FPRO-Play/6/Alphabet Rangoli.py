def rangoli(N):
    al = "abcdefghijklmnopqrstuvwxyz"
    ls = []
    for i in range(N-1, -1, -1):
        x = "-".join(al[i:N])
        ls.append((x[::-1]+x[1:]).center(4*N-3, "-"))
    return "\n".join(ls + ls[N-2::-1]*(N>1))
