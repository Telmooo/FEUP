def division(a, b):
    try:
        return f"{a}/{b} = {a/b}"
    except ZeroDivisionError:
        return "can't divide by 0!"
    except:
        return "unsupported operand type(s) for division"
