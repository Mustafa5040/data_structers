seconds = int( input("Please enter the seconds: ") )

hour = seconds // 3600
minutes = (seconds % 3600) // 60
r_seconds = (seconds % 3600) % 60

print(f"{seconds} seconds is {hour} hours {minutes} minutes {r_seconds} seconds")

