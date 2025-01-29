def findMiddle(a, b, c):
    
    if a > b:
        if b > c: 
            maximum, middle, minimum = a, b, c
        elif a > c:  
            maximum, middle, minimum = a, c, b
        else:  
            maximum, middle, minimum = c, a, b
    else:  
        if a > c:  
            maximum, middle, minimum = b, a, c
        elif b > c: 
            maximum, middle, minimum = b, c, a
        else:  
            maximum, middle, minimum = c, b, a
    
    
    result = f"The values are: {a}, {b}, {c}.\n"
    result += f"The minimum value is: {minimum}\n"
    result += f"The maximum value is: {maximum}\n"
    result += f"The middle value is: {middle}"
    
    return result