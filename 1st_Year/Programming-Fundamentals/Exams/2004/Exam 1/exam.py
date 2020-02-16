'''
Final score
'''
def show_score(score):
    return f"score = {score}"

'''
Calculate score
'''
def calc_score(t1, t2, ex):
    return 0.2*t1 + 0.3*t2 + 0.5*ex

'''
Round score
'''
def round_score(score):
    return score//2*2 if score%1==0.5 else round(score, 0)

'''
Classification
'''
def classif(score):
    if 0<score<10:
        return "classification = bad"
    elif 10<=score<14:
        return "classification = okay"
    elif 14<=score<18:
        return "classification = good"
    elif 18<=score<=20:
        return "classification = very good"
    else:
        return "classification = error"

'''
Full Classification
'''
def full_score(t1, t2, ex):
    score = round_score(calc_score(t1, t2, ex))
    clf = classif(score)
    return f"score = {score} \n{clf}"
