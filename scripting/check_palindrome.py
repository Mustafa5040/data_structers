input_str = input("Please enter a string to check whether palindrome or not: ")


l = 0
h = len(input_str)-1
is_palindrome = True
,
while(l < h):
    if(input_str[l] != input_str[h]):
        is_palindrome = False
        break
    is_palindrome = True
    l+=1
    h-=1
input_str = input_str.lower()
print(f"is {input_str} palindrome? The answer is","yes" if is_palindrome else "no")
      
