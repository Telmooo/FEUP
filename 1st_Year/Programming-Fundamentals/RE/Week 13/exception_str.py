"""
Exception string
"""
def exception_str(f):
    try: f()
    except Exception as e:
        return str(e)
    else: return "No exception was raised"
