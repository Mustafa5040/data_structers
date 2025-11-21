amount = int(input("Enter amount of the money in cents (pennies) : "))

dollar_nums = amount // 100

remaining_amount = amount % 100

quarters = remaining_amount // 25

remaining_amount = remaining_amount % 25

dimes = remaining_amount // 10

remaining_amount = remaining_amount % 10

nickles = remaining_amount // 5

remaining_amount = remaining_amount % 5

pennies = remaining_amount


print(f"{amount} Pennies is {dollar_nums} dollars {quarters} quarters {dimes} dimes {nickles} nickles {pennies} pennies")