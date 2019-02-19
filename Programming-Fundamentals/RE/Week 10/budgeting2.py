"""
Budget version 2.0
"""
def budgeting2(budget, products, wishlist):

    def linear_combination(constraints, array = []):
        if len(constraints) == 0: return [array]
        combinations = []
        for i in range(constraints[0]+1):
            combinations += linear_combination(constraints[1:], array+[i])
        return combinations

    M = 0
    C = []
    ls = sorted(wishlist.items(), key = lambda x: products[x[0]], reverse=True)
    x, y = zip(*ls)
    prices = [products[k] for k in x]
    combinations = linear_combination(y)
    for c in combinations:
        S = sum(k[0]*k[1] for k in zip(c, prices))
        if S <= budget:
            if S > M:
                C = c
                M = S
            if S == M and c > C:
                C = c

    return {k[0]: k[1] for k in zip(x, C) if k[1]!=0}
