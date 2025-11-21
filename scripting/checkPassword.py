def isValidPassword(password):

    isLen = len(password) >= 10
    isAlphaOrNum = isalnum(password)
    digit_count = 0
    for i in password:
        if i >= '0' and i <= '9' digit_count+= 1
    