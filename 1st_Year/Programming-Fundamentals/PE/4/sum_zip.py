def sum_zip(funcs, args):
    for a in args:
        l = [f(a) for f in funcs]
        yield (l, sum(l))
