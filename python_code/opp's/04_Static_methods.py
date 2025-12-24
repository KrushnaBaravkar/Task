# Staric methods in python = are the methods that are bound to the class and not the object of the class.
# They can be called on the class itself, rather than on instances/objects of the class.

# Polymorphosm in python  +
# Tracking the total number of cars created .

class Car:
    total_cars = 0

    def __init__(self, model, company):
        self.model = model
        self.__company = company
        Car.total_cars += 1  
    def full_name(self):
        print(f"{self.__company} {self.model}")

    def get_company(self):
        return self.__company + " !"
    
    def fuel_type(self):
        return "Petrol or Deisel"
    
    # Static method to get total cars created.
    @staticmethod
    def general_discription():
        return "Cars are vehicles used for transportation."

class Electirc_car(Car):
    def __init__(self, battery_size, Model, company):
        self.battery_size = battery_size
        super().__init__(Model, company)
    def full_name(self):
        print(f"Electric car {self.company} {self.model} having battery size of {self.battery_size}")
    
    def fuel_type(self):
        return "Electricity"


my_car = Car("Safari", "Tata")
print(my_car.general_discription())  # this line is also working because static method can be called by both class and object, but it should not accessed by object.
# python intrnally converts my_car.general_discription() to Car.general_discription(), thats why the above line is working.
print(Car.general_discription())