'''
Conway's Game of Life
A zero player game in a 2D grid
Each cell has a state: Dead or Alive
Natural choice will decide the fate of the cells

Grid example:
				|x-1, y-1	x, y-1	x+1, y-1|
				|x-1, y		x, y	x+1, y	|
				|x-1, y+1	x, y+1	x+1, y+1|

Game Rules: Depending on the state of the cell, the cell can
		either go to the next generation and tell the story
		or die. If it's dead, magic can revive it.

		If the cell is alive, but has less than 2 neighbours
		*dead*
		If the cell is alive, but has more than 3 neighbours
		*dead*
		If the cell is alive, but has 2 or 3 neighbours
		*idle*
		If the cell is dead, and has exactly 3 neighbours
		*back to life*
'''

from random import randint
import matplotlib.pyplot as plt
import matplotlib.animation as animation

def generate_world(N):
    '''
    Generates a random world for the game
    '''
    world = list()
    #this can be easily improved using numpy
    for _ in range(N):
        world.append([randint(0, 1) for __ in range(N)])

    return world

def update_cell(frames, screen, world, N):
    '''
    Updates each cell according to the game rules
    Alive -> 1
    Dead -> 0
    '''
    new_world = world.copy()
    for x in range(N):
        for y in range(N):
            neighbours = (world[(x-1) % N][(y-1) % N] + world[x][(y-1) % N] +
                          world[(x+1) % N][(y-1) % N] + world[(x-1) % N][y] +
                          world[(x+1) % N][y] + world[(x-1) % N][(y+1) % N] +
                          world[x][(y+1) % N] + world[(x+1) % N][(y+1) % N])

            #if the cell is active
            if world[x][y] == 1:
                if neighbours > 3 or neighbours < 2:
                    new_world[x][y] = 0

            #if the cell is dead
            else:
                if neighbours == 3:
                    new_world[x][y] = 1

    screen.set_data(new_world)
    world = new_world
    return screen

def main():
    '''
    Loads the game
    '''
    #variable must be global for it to work
    global ani
    N = 300          #size of the world, be careful modifying this
    world = generate_world(N)   #generates a world

    figure, ax = plt.subplots()     #creates the figure and multiple subplots
    screen = ax.imshow(world)       #displays the image formed by the world
    ani = animation.FuncAnimation(figure, update_cell,
                                  fargs=(screen, world, N))

    plt.axis("off")
    plt.show()

main()
