def isConsecutive():
    num1,num2,num3 = [a for a in input("Enter three number with decimal seperator(,): ").split(',')]

    if((num1+1 == num2 and num2+1 == num3) or (num3+1 == num2 and num2+1 == num1)):
        return True
    return False
