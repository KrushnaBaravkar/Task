# Polymorphosm in python  +
# Tracking the total number of cars created .

class Car:
    total_cars = 0

    def __init__(self, model, company):
        self.model = model
        self.__company = company
        Car.total_cars += 1  # Increment total cars when a new car is created.
        
    def full_name(self):
        print(f"{self.__company} {self.model}")

    def get_company(self):
        return self.__company + " !"
    
    def fuel_type(self):
        return "Petrol or Deisel"

class Electirc_car(Car):
    def __init__(self, battery_size, Model, company):
        self.battery_size = battery_size
        super().__init__(Model, company)
    def full_name(self):
        print(f"Electric car {self.company} {self.model} having battery size of {self.battery_size}")
    
    def fuel_type(self):
        return "Electricity"


my_car = Electirc_car("15W", "Safari", "Tata")
# print(my_car.__company)
# print(my_car.get_company())
print(my_car.fuel_type())  # Polymorphosm in action.

my_car1 = Car("Safari", "Tata")
print(my_car1.fuel_type())  # Polymorphosm in action.

print(Car.total_cars)  # Accessing class variable to see total cars created.