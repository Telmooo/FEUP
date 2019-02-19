"""
Recursive exceptions
"""
def rec_exceptions(l):
    ls = []
    if isinstance(l, list):
        for f in l:
            ls += rec_exceptions(f)
    else:
        try:
            x = l()
        except Exception as e:
            ls.append(e)
        else:
            ls += rec_exceptions(x)
    return ls
