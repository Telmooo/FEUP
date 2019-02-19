"""
Parse a tuple
"""
def parse(filename):
    with open(filename) as f:
        text = f.read()
    
    chars = text.split("\n")
    tp = "("
    
    for char in chars:
        if char.strip() == "(":
            tp += char.strip()
        
        else:
            tp += char.strip() + ","
    try:
        return eval(tp.strip(",") + ",)")
    except:
        return ()
