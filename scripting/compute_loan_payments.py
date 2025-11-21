annual_interest_rate = float(input("Enter the annual interest rate (%): "))
number_of_years = int(input("Enter the number of years: "))
loan_amount = float(input("Enter the loan amount: "))

monthly_interest_rate = (annual_interest_rate / 1200)
monthly_payment = loan_amount* monthly_interest_rate / (1- (1 / ((1 + monthly_interest_rate) ** (number_of_years*12)) ) )