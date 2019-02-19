"""
Map, Filter & Reduce
"""
def reduce_map_filter(args):
    from functools import reduce
    if isinstance(args[2], list):
        op = eval(args[0])
        f = args[1]
        if args[0] == "reduce":
            return op(f, args[2])
        return list(op(f, args[2])) 
    op = eval(args[0])
    f = args[1]
    if args[0] == "reduce":
        return op(f, reduce_map_filter(args[2]))
    return list(op(f, reduce_map_filter(args[2]))) 
