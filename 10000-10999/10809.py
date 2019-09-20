string=input()
basic='abcdefghijklmnopqrstuvwxyz'

for ch in basic:
    if ch in string:
        print(string.find(ch),end=" ")
    else:
        print("-1",end=" ")
