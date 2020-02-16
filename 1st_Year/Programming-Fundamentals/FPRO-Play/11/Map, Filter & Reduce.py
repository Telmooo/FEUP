from functools import reduce
map_filter_reduce = lambda x, f1, f2, f3: reduce(f3, map(f2, filter(f1, x)))
