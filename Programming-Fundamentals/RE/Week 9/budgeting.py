"""
Budgeting
"""
def budgeting(budget, products, wishlist):
    from collections import OrderedDict

    s = sum(products[prod]*wishlist[prod] for prod in wishlist)

    if s <= budget:
        return wishlist

    else:
        new_list = OrderedDict(sorted(wishlist.items(), key = lambda x: products[x[0]]))
        for prod in new_list:
            while wishlist.get(prod, 0) > 0:
                wishlist[prod] -= 1
                s -= products.get(prod)
                if wishlist[prod] == 0:
                    del wishlist[prod]
                if s <= budget:
                    return wishlist
    return wishlist
