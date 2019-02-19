def adigits(n1, n2, n3):
    """
    build the highest possible number out of the combination of 3 digits
    """
    digits = n1 + n2 + n3
    combination = 0
    for i in range(3):
        new_digits = ""
        #gives the highest character based on ASCII Code
        highest = max(digits)
        control = True

        for digit in digits:
            #if control is True removes the highest number from the string
            if digit == highest and control:
                control = False
                continue
            new_digits += digit

        digits = new_digits
        combination += int(highest) * (10 ** (2-i))

    return combination
