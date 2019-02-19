#Calculate Pi using Variance of Monte Carlo Method (CH01)

'''
Estimating π using Monte Carlo Method:
    Let's assume we have a circle of radius 0.5 enclosed by a 1x1 (2*radius) square.
    The area of the circle would be π*(r**2)=π/4, and the area of the square would be 1
    If we do the ratio of the areas ρ = Area of the circle / Area of the square ⇔
                                 ⇔ ρ = (π/4) / 1 ⇔
                                 ⇔ ρ = (π/4)
    Now let's consider that we generate an indefinite number of points that can either be inside or outside the circle,
        and would always be withint the square, so we could get an approximation of the ratio of the areas
                     π/4 ≈ (points_inside / points_created) ⇔
                    ⇔ π ≈ 4 * (points_inside / points_created)
'''

import time
from statistics import stdev
from statistics import mean
import random
import math

def verify_condition(x, y):
    '''
    Checks if the point is inside the circle of radius 1
    '''
    return math.sqrt(x**2 + y**2) <= 1
        
def estimate_pi(shots):
    '''
    For a certain number of "shots", an estimation of pi is created using Monte Carlo's Method.
    '''
    inside = 0
    for _ in range(shots):
        x = random.uniform(-1, 1)
        y = random.uniform(-1, 1)
        if verify_condition(x, y):
            inside += 1
    pi = 4* (inside / shots)
    return pi

def create_estimations():
    '''
    Creates a list of 100 estimations for pi, where the standart deviation of the values is inferior to 0.005 
    '''
    needles = 1000
    estimations = []

    for _ in range(100):
        pi = estimate_pi(needles)
        estimations.append(pi)

    while stdev(estimations) >= 0.005:
        estimations = []
        needles = needles * 2
        for _ in range(100):
            pi = estimate_pi(needles)
            estimations.append(pi)  
    return estimations, needles
        
def calculate_pi():
    '''
    Calculates pi using a list of estimations for pi
    Returns the value of pi, the number of shots used for Monte Carlo's Method for estimating pi and the time spent for calculating pi.
    '''
    time_start = time.time()
    estimations, needles = create_estimations()
    final_estimation_pi = mean(estimations)
    
    time_end = time.time()
    time_elapsed = str(time_end - time_start)
    return final_estimation_pi, needles, time_elapsed

estimated_pi, needles, time_elapsed = calculate_pi()

print()
print("This estimation was generated in:", time_elapsed[:2], end = "s.")
print()
print("Number of needles used for this estimation:", needles, end = ".")
print()
print("Estimation for pi (π):", estimated_pi, end = '.')
print()
print()
print("Value of pi (π):", math.pi, end = ".")
