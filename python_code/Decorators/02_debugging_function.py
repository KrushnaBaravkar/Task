# Debugging function using decorator

def debug_function(func):
    def wrapper(*args, **kwargs):
        args_values = ', '.join(str(arg) for arg in args)
        kwargs_values = ', '.join(f"{k}={v}" for k, v in kwargs.items())
        print(f"calling: {func.__name__} with args {args_values} and kwargs {kwargs_values}")
        return func(*args, **kwargs)
      
    return wrapper 


@debug_function  # toll to the following function.
def greeting(name, greeting = "hello"):
    return f"{greeting}, {name}"

greeting("Krushna", "Hi")

# kwargs are the key valued arguments, in which arguments are the name specified at in the function while defining and the key are the values passed dueing calling the function.
# Ex. argument is company in the function but while passing will pass "TATA", therefor tata is the key and the company is the argumant.
# args are the arguments that are passed during calling the function without specifying the name of the argument