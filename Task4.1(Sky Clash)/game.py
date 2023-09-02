from Villain import *
from os import system, name
import random
def clear():
   if name == 'nt':
      _ = system('cls')
   else:
    _ = system('clear')

def main():
    gru = GruVillain()
    vector = VectorVillain()
    mode = 0
    print("\033[1;37;40m1. 1 Player\n2. 2 Players")
    while True:
        mode = int(input("Choose Mode: "))
        if mode == 1 or mode == 2:
            break 
    round_number = 1
    while gru.health > 0 and vector.health > 0:
        clear()
        print(f"\033[1;37;40mRound {round_number}")
        print(f"{gru.color}{gru.name}'s ==> Health: {gru.health}       Energy: {gru.energy}\033[1;37;40m")
        print(f"{vector.color}{vector.name}'s ==> Health: {vector.health}       Energy: {vector.energy}\033[1;37;40m")
        if not gru.weapons and not gru.shields:
            if not vector.weapons and not vector.shields:
                print(f"\033[1;31;40mBoth have no shields or weapons.\n{gru.color}DR{vector.color}AW\033[1;37;40m")
            else :
                print(f"\033[1;31;40m{gru.name} has no shields or weapons.\n{gru.name} loses!\033[1;37;40m")
            break

        if not vector.weapons and not vector.shields:
            print(f"\033[1;31;40m{vector.name} has no shields or weapons.\n{vector.name} loses!\033[1;37;40m")
            break

        gru_action = gru.choose()
        if mode == 2:
            vector_action = vector.choose()
        else :
            vector_action = random.choice(vector.weapons+vector.shields)
        vector.use(vector_action)
        gru.use(gru_action)
        if isinstance(gru_action,Weapon):
            gru.attack(vector,gru_action)
        if isinstance(vector_action,Weapon):
            vector.attack(gru,vector_action)
        gru.update_gadgets()
        vector.update_gadgets()

        round_number += 1
    if vector.health <= 0 and gru.health <= 0 :
        print(f"{gru.color}DR{vector.color}AW\033[1;37;40m")
    elif vector.health <= 0 :
        print(f"\033[1;32;40m{gru.name} wins!\033[1;37;40m")
    elif gru.health <= 0 :
        print(f"\033[1;32;40m{vector.name} wins!\033[1;37;40m")
    

if __name__ == "__main__":
    main()