# use decorator to make the model read only. no-one can overwrite it.

class Car:
    total_cars = 0

    def __init__(self, model, company):
        self.__model = model  # firstly make model attribute private 
        self.__company = company
        Car.total_cars += 1  
    def full_name(self):
        print(f"{self.__company} {self.__model}")

    def get_company(self):
        return self.__company + " !"
    
    def fuel_type(self):
        return "Petrol or Deisel"
    
    # then access model attribute using property decorator.
    @property
    def model(self):
        return self.__model
    
class Electirc_car(Car):
    def __init__(self, battery_size, Model, company):
        self.battery_size = battery_size
        super().__init__(Model, company)
    def full_name(self):
        print(f"Electric car {self.company} {self.model} having battery size of {self.battery_size}")
    
    def fuel_type(self):
        return "Electricity"


my_car = Car("Safari", "Tata")
print(my_car.model) # accessing the model using the property decorator.
# accessing done like the attribute not like the method.(my_car.model())
# cant do overwriting now as following.
'''
my_car.model = "Tiago"
print(my_car.model)
'''