# Danny Radosevich
# Lab 9
# Written for UWYO COSC 2030
import collections

def rever(toRever):
    revDeq = collections.deque([])
    returnVal = ""
    for x in range(len(toRever)):
        revDeq.append(toRever[x])
    for x in range(len(toRever)):
        returnVal += revDeq.pop()
    return returnVal

def parenCheck(toCheck):
    checkDeq = collections.deque([])
    for x in range(len(toCheck)):
        if toCheck[x] == '(':
            checkDeq.appendleft(toCheck[x])
        elif toCheck[x] == ')' and len(checkDeq):
            checkDeq.popleft()
        else:
            return False
    if len(checkDeq) == 0:
        return True
    return False

    ##return not len(checkDeq) #return for the size evaluation

#think of this area as main
print("Starting reversal\n")
print(rever("sekopog"))
print(rever("peehsehttaeb"))
print(rever("sgnirtsgnisreverfoderitsyuguoyera"))
print(rever("maiesuaceb"))

if(parenCheck("(()((((()()()((()(((()()()()(((()(()()()(())()())()()))))()()()))()))()())())())))")):
    print("Paren string 1 is good") #should be
else:
    print("Paren string 1 is bad")

if(parenCheck("()((((((()(((((()((()()()()()(()))))))))()))()(())(())(((((()()(())))(()()())(()))")):
    print("Paren string 2 is good")
else:
    print("Paren string 2 is bad") #should be

if(parenCheck("(()((()(()()(()(((((()()(()()()((((()()(()()))()))))()()())))))()()())()()))())())")):
    print("Paren string 3 is good") #should be
else:
    print("Paren string 3 is bad")

if(parenCheck("(()()(((()()(()(()()(()()()()()()(()(((((((((())())))))()))))()()))()())()()))()))")):
    print("Paren string 4 is good") #should be
else:
    print("Paren string 4 is bad")

if(parenCheck("(())(()(())()(()(()()((())()(()(()()(()()()()())((()((())(())(()))(())())(()())())")):
    print("Paren string 5 is good")
else:
    print("Paren string 5 is bad") #should be

if(parenCheck("()(()(()))((())((()()()(()()((((()(()((()()(())()(())()())()(()()))(((())))())(())")):
    print("Paren string 6 is good")
else:
    print("Paren string 6 is bad") #should be
