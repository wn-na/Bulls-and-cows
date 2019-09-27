import random

GAME_SIZE = 3

def init_rand():
    arr = [0,1,2,3,4,5,6,7,8,9]
    while arr[0] == 0:
        random.shuffle(arr)
    arr = arr[0:GAME_SIZE]
    return int(''.join(map(str,arr)))

def user_input():
    while True:
        user_input = input()
        if user_input.isdigit():
            if len(user_input) == GAME_SIZE:
                if len(list(set(map(str,user_input)))) == GAME_SIZE:
                    return user_input
                else:
                    print("중복된 숫자가 존재합니다")
            else:
                print("범위 초과입니다.")
        else:
            print("숫자가 아닙니다.")

def checknum(com, user):
    strike, ball = 0, 0
    com = list(map(str,[int(d) for d in str(com)]))
    user = list(map(str,[int(d) for d in str(user)]))
    for i in range(GAME_SIZE):
        for j in range(GAME_SIZE):
            if com[i] == user[j]:
                if i == j:
                    strike += 1
                else:
                    ball += 1
    return strike, ball

if __name__ == "__main__":
    com_num = init_rand()
    while True:
        print("입력해주세요")
        user_num = user_input()

        strike, ball = checknum(com_num, user_num)

        if strike == 3:
            print("축하드립니다! 정답 : ", com_num)
            break
        else:
            if strike == 0 and ball == 0:
                print(user_num,"OUT!!!")
            else:
                print(strike,"strike",ball,"ball !!")
