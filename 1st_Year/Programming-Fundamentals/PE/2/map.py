def map(pos, steps):
    proc = steps.split("-")
    ps = list(pos)
    for step in proc:
        if step == "up":
            ps[1] += 1
        elif step == "down":
            ps[1] -= 1
        elif step == "right":
            ps[0] += 1
        elif step == "left":
            ps[0] -=1
    return tuple(ps)
