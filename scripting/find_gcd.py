num1,num2 = 25,15
gcd = 1

for i in range(2,min(num1,num2)+1):

    if(num1 % i == 0 and num2 % i == 0):
        gcd = i
    
print(gcd)