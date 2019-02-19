def discard_middle(s):
    return "" if len(s) <= 3 else "".join((s[:2], s[-2:]))
