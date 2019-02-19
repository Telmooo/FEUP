def nested_exceptions(tree):
    t = ()
    for item in tree:
        if callable(item):
            try:
                item()
                t += (False,)
            except:
                t += (True,)
        else:
            t += (nested_exceptions(item),)
    return t
