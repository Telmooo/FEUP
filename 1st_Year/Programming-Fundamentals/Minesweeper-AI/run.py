"""
AI
"""

#Standart Libraries
from time import time, strftime, gmtime

#My Libraries
from AI import AI

def wait():
    input("Press enter to continue...")

DEBUG = input("Debug Mode(Y/N): ")

while DEBUG.lower() not in {"y", "n"}:

    print("Invalid input, please choose according to the options")
    DEBUG = input("Debug Mode(Y/N): ")

else:
    if DEBUG.lower() == "y":
        DEBUG = True

    else:
        DEBUG = False

if not DEBUG:
    #Debug mode deactivated
    PLAY_WIN = input("Play till win?(Y/N): ")

    while PLAY_WIN.lower() not in {"y", "n"}:

        print("Invalid input, please choose according to the options")
        PLAY_WIN = input("Debug Mode(Y/N): ")

    else:
        if PLAY_WIN.lower() == "y":
            PLAY_WIN = True

        else:
            PLAY_WIN = False

    if not PLAY_WIN:

        N = input("Games to play: ")

        while not N.isdigit():

            print("Must be a positive integer")
            N = input("Games to play: ")

        else:
            if int(N) == 0:
                print("Must play atleast 1 game")
                N = input("Games to play: ")

            else:
                N = int(N)
    else:
        N = 1

else:
    #debug mode
    PLAY_WIN = False
    N = 1


WIN = False
DEAD = False
GAMES_PLAYED = 0
GAMES_WON = 0
GAMES_LOST = 0
BEST_TIME = None

#while there's game to play
ai = AI(DEBUG)
while N > 0:
    t0 = time()
    ai.dead = False
    ai.board_info()
    #only activated if in debug mode
    if DEBUG:
        wait()

    first_guesses = True

    while not (WIN or DEAD):

        if first_guesses:

            #verifies there's no possible target
            ai.nextTarget(False)
            if DEBUG:
                wait()

            if len(ai.targets) == 0:

                ai.early_guesses(first_guesses)
                if DEBUG:
                    wait()

                ai.clickTargets()
                if DEBUG:
                    wait()

            #if there is a target that's not random, disable early guessing
            else:
                ai.clickTargets()
                first_guesses = False
                if DEBUG:
                    wait()

        else:
            #get next target
            ai.nextTarget()
            if DEBUG:
                wait()

            ai.clickTargets()
            if DEBUG:
                wait()

            #tries to get new targets, without being random targets
            ai.nextTarget(False)
            if DEBUG:
                wait()

            while len(ai.targets) != 0:

                ai.clickTargets()
                if DEBUG:
                    wait()

                ai.nextTarget(False)
                if DEBUG:
                    wait()

                #check game state
                game_state = ai.check()

                if game_state != -1: break

        #check game state
        game_state = ai.check()

        if game_state == 1:
            WIN = True

        if game_state == 0:
            DEAD = True

    t1 = time()

    if WIN:
        time = strftime('%H:%M:%S', gmtime(t1-t0))
        WIN = False
        GAMES_PLAYED += 1
        GAMES_WON += 1
        N -= 1

        print()
        print("Game won!")
        print(f"Current win rate: {100*GAMES_WON/GAMES_PLAYED}%")
        print(f"Time to solve: {time}.")

        if BEST_TIME is None:
            print()
            print(f"New best time {time}.")
            BEST_TIME = time

        elif time < BEST_TIME:
            BEST_TIME = time
            print()
            print(f"New best time {time}.")

        if DEBUG:
            wait()

        if N != 0:
            ai.restart_game()
            if DEBUG:
                wait()

    else:
        DEAD = False
        GAMES_PLAYED += 1
        GAMES_LOST += 1

        if PLAY_WIN:
            pass

        else:
            N -= 1

        print()
        print("Game lost!")
        print(f"Current win rate: {round(100*GAMES_WON/GAMES_PLAYED, 1)}%")
        print(f"Games played: {GAMES_PLAYED}")
        print(f"Games won: {GAMES_WON}")
        print(f"Games lost: {GAMES_LOST}")

        if DEBUG:
            wait()

        if N != 0:
            ai.restart_game()
            if DEBUG:
                wait()

print()
print("---------------------------------------------------------------------")
print("Final results:")
print(f"Games played: {GAMES_PLAYED}")
print(f"Games won: {GAMES_WON}")
print(f"Games lost: {GAMES_LOST}")
print(f"Win rate: {100*GAMES_WON/GAMES_PLAYED}%")
print(f"Best time: {BEST_TIME}")
