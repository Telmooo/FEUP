def mastermind(g1, g2, g3, c1, c2, c3):
    """
    evaluate a line of the mastermind game
    """
    guesses = g1 + g2 + g3
    key = c1 + c2 + c3
    points = 0

    #################################################################

    control = 0
    new_guesses = ""
    #check 3 pointers and deletes every used guess and key
    for guess in guesses:
        new_key = ""
        index = 0
        keep_guess = True
        for k in key:
            keep_key = True
            if guess == k and control == index:
                points += 3
                keep_key = False
                keep_guess = False

            index += 1
            if keep_key:
                new_key += k
                continue

            new_key += " "

        key = new_key
        if keep_guess:
            new_guesses += guess

        control += 1

    #################################################################

    #Creates new version of guesses and key with unused guesses and keys
    guesses = new_guesses
    new_key = ""
    #clears white spaces in key
    for char in key:
        if char != " ":
            new_key += char

    key = new_key

    #################################################################

    #check 1 pointers and deletes every key used if found correspondence
    new_key = ""
    for guess in guesses:
        if guesses == "" or key == "":
            break
        control = True

        for k in key:
            if guess == k and control:
                points += 1
                control = False
                continue

            new_key += k
        key = new_key

    return points
