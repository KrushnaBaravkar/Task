# print the time required to execute a function using decorators.

import time

def timer(func):
    def wrapper(*args, **kwargs):
        start_time = time.time()
        result = func(*args, **kwargs)
        end_time = time.time()
        print(f"Execution time of {func.__name__}: {end_time - start_time} seconds")
        return result
    return wrapper  

# using decorator that ensures the function below that will run after the function mention in the decorator.
@timer   # it is the toll to the following function.
def example_function(n):
    time.sleep(n)

example_function(2)