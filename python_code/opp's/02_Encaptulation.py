# modify the the car attribute and incapulate the brand attribute and make getter method to get it.

class Car:
    def __init__(self, model, company):
        self.model = model
        self.__company = company
        # adding __ to the attribute made it private so that no longer object can access that attribute.

    def full_name(self):
        print(f"{self.__company} {self.model}")

    # Getter method to access the private attribute.(Getter method)
    def get_company(self):
        return self.__company + " !"

class Electirc_car(Car):
    def __init__(self, battery_size, Model, company):
        self.battery_size = battery_size
        super().__init__(Model, company)
    def full_name(self):
        print(f"Electric car {self.company} {self.model} having battery size of {self.battery_size}")


my_car = Electirc_car("15W", "Safari", "Tata")
print(my_car.__company)
print(my_car.get_company())