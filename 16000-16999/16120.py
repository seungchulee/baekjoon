x = input()
data = list()
for w in x:
    if len(data) >= 4:
        if ''.join(data[len(data)-4:len(data)]) == "PPAP":
            data.pop();data.pop();data.pop();data.pop()
            data.append("P")
    data.append(w)

if ''.join(data) == "PPAP" or ''.join(data) == "P":
    print("PPAP")
else:
    print("NP")
