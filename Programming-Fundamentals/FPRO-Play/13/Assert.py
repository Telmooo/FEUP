def kelvin_to_fahrenheit(temp):
    if temp < 0:
        return AssertionError("Colder than absolute zero!")
    x = int(temp*(9/5) - 459.67 + 0.5)
    return x
