class Car:
    def __init__(self, model, company):
        self.model = model
        self.company = company
    # here self is the connection string use to connect the object of that perticular calss to its attributes.
    
    # adding functionality to the class.                                               
    def full_name(self):
        print(f"{self.company} {self.model}")

    def full_name_(self):
        return (f"{self.company} {self.model}")
    # above both the methods are for same work but different structure.

my_car = Car("Model S", "Tesla")
print(my_car.model)
print(my_car.company)
my_car.full_name()
print(my_car.full_name_())

my_new_car = Car("Safari", "Tata")
my_new_car.full_name()
