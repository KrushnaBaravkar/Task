class Car:
    def __init__(self, model, company):
        self.model = model
        self.company = company

    # adding functionality to the class.                                               
    def full_name(self):
        print(f"{self.company} {self.model}")

    def full_name_(self):
        return (f"{self.company} {self.model}")
    
# following is the example of the inheratance of the calss.
class Electirc_car(Car):
    def __init__(self, battery_size, Model, company):
        self.battery_size = battery_size
        super().__init__(Model, company)
    def full_name(self):
        print(f"Electric car {self.company} {self.model} having battery size of {self.battery_size}")


my_car = Electirc_car("15W", "Safari", "Tata")
# my_car.model = "Safari"     # able to access the attrabute of the Car class using the object of the doughter calss that is Electric_car.
# my_car.company = "Tata"     # able to access the attrabute of the Car class using the object of the doughter calss that is Electric_car.
print(my_car.model)
print(my_car.company)
print(my_car.battery_size)
my_car.full_name()
