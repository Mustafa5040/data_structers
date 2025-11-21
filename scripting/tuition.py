initial_tuition = 10000
new_tutition = 10000
number_of_years = 0

while(new_tutition < initial_tuition*2):
    new_tutition += new_tutition * 0.07
    number_of_years += 1

print(number_of_years)