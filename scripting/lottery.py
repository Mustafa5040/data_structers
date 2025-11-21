import random
guess = int( input("Enter the your lottery pick (two digits): ") ) 
lottery = random.randint(10,99)


lot_digit_1 = lottery % 10
lot_digit_2 = (lottery // 10) % 10

guess_digit_1 = guess % 10
guess_digit_2 =(guess // 10) % 10

if(guess == lottery){
    print("Exact Match")
}
elif (lot_digit_1 == guess_digit_2 and lot_digit_2 = guess_digit_1){
    print( "Match All Digits")
}
elif( guess_digit_1 == lot_digit_1 or guess_digit_1 == lot_digit_2 or guess_digit_2 == lot_digit_1 or guess_digit_2 == lot_digit_2 ){
    print("Match one digit")
}
else:
    print("Sorry, no match")
