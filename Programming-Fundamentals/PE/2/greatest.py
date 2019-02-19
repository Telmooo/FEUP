def greatest(num):
    return int(("".join(sorted(str(num), key=lambda x: -int(x)))))
