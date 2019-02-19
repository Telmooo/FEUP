"""
Hash Collisions
"""
def collisions(list):
    hash8 = {}
    for i in list:
        h = sum(map(int, str(i)))%8
        hash8[h] = hash8.get(h, 0) + 1
    return hash8
