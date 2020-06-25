x, n = map(int, input().split())

if n == 1:
    if x < 0:
        print("INFINITE")
    else:
        print("0")
elif n == 0:
    if x > 0:
        print("INFINITE")
    else:
        print("0")
elif n % 2 == 1:
    print("ERROR")
else:
    if x > 0:
        print("%d"%((x-1)/(n/2)))
    else:
        print("0")
