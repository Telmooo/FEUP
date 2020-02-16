def fight(heroes, villain):
    vc = villain["category"]
    vh = villain["health"]
    for hero in heroes:
        if hero["category"] == vc:
            if hero["health"] >= vh:
                return f"{hero['name']} defeated the villain and now has a score of {hero['score']+1}"
            else:
                vh -= hero["health"]/2
    return f"{villain['name']} prevailed with {round(vh, 1)}HP left"
