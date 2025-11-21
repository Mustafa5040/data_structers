def calculateDigits(int x):
    digits_in_order = list()
    while(True):
        digits_in_order.append(x % 10) // first digit
        x //= 10

        if(x == 0) break

