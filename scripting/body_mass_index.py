height, weight =   tuple([float(a) for a in (input("Please enter your height(meters) and weight(kilograms) with decimal seperator: ").split(','))])

bmi = weight / (height**2)

print("your bmi is ",end='')
if(bmi  < 18.5):
    print("Underweight")
elif(bmi < 25):
    print("Normal")
elif(bmi < 30):
    print("Overweight")
else:
    print("Obese")