"""
Compatible Matrices
"""
def compatible(A, B):
    try:
        assert len(A[0])==len(B)
    except AssertionError: return AssertionError("A and B cannot be multiplied")
    else:
        return "A and B can be multiplied"
