from math import sqrt
inputs1 = input("Please enter the first point with decimal seperator: (x,y): ")

x1,y1 = inputs1.split(',')

inputs2 = input("Please enter the second point with decimal seperator: (x,y): ")

x2,y2 = inputs2.split(',')

distance = sqrt( (x2-x1)**2 + (y2-y1)**2 )

print(distance)