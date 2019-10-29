# only input is number and 3 digits
# Each digit is not duplicated
# ex) input = 123, 157, 012, etc...

com, user = ''.join(str(x) for x in random.sample(range(0, 10), 3)), 0
while com != user:
    s, b, user = 0, 0, input()
    for i in range(3):
        b, s = b + com.count(user[i]), s + (com[i] == user[i])
    print("Correct" if s == 3 else ((s, b - s) if b else "OUT"))
