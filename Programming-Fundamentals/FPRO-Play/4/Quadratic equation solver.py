def solver(a, b, c):
    d = b**2 - 4*a*c
    sol = []
    if a == 0: pass
    elif d == 0: sol = [-b/(2*a)]
    elif d > 0:
        sol = [(-b + d**0.5) / (2*a), (-b - d**0.5) / (2*a)]
        sol.sort()
    return sol
