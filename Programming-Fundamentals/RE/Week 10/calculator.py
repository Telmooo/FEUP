"""
Calculator
"""
def calculator(expr):
    if isinstance(expr, tuple):
        return eval("".join(str(calculator(x)) if isinstance(x, tuple) else str(x) for x in expr))
    return expr
