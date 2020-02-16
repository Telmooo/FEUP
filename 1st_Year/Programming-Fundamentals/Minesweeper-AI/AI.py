"""
MINESWEEPER AI
"""

#Third-Party Libraries
import pyautogui as pgui
import numpy as np

#My Libraries
import auxiliar_functions as auxf
from tile import Tile

class AI:

    def __init__(self, debug=False):
        """Set AI variables"""
        #debugging
        self.debug = debug

        #variables for image processing (Windows)
        self.blank_tile = "./data/blank_tile.png"
        self.tile1 = "./data/1.png"
        self.tile2 = "./data/2.png"
        self.tile3 = "./data/3.png"
        self.tile4 = "./data/4.png"
        self.tile5 = "./data/5.png"
        self.tile6 = "./data/6.png"
        self.tile7 = "./data/7.png"
        self.tile8 = "./data/8.png"
        self.unrevealed_tile = "./data/unrevealed_tile.png"
        self.flag = "./data/flag.png"
        self.game_state = tuple(x-1 for x in pgui.locateCenterOnScreen("./data/restart.png"))

        #variables for the algorithm
        self.board = []
        self.tile_size = 0
        self.width = 0
        self.height = 0
        self.targets = []
        self.dead = False

    #-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    #Auxiliar function for visualizing the current matrix
    def __repr__(self):
        #default color
        default = '\x1b[48;5;16m' + '\x1b[38;5;15m'
        reset = '\x1b[0m'
        out = []
        out.append(default + "-"*(4*self.width+1) + reset)
        for row in self.board:
            line = []
            for tile in row:
                #targeted tiles marked as red
                if tile.istarget:
                    if tile.bomb:
                        color = '\x1b[48;5;9m' + '\x1b[38;5;15m'
                    else:
                        color = '\x1b[48;5;10m' + '\x1b[38;5;15m'
                #linked tiles marked as mangenta
                elif tile.linked:
                    color = '\x1b[48;5;5m' + '\x1b[38;5;15m'
                #else default color
                else:
                    color = default

                if tile.value is None:
                    line.append(color + "   " + reset)
                else:
                    line.append(color + " "+str(tile.value)+" " + reset)
            out.append(default + "|" + "|".join(line) + "|" + reset)
            out.append(default + "-"*(4*self.width+1) + reset)
        return "\n".join(out)

    #-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    #Called one time for setting essential information about the game
    def board_info(self):
        """Get board information"""
        #On a 2D plane: tile[i][j]; i-> x axis; j-> y axis
        #However we'll invert this order on the matrix
        #matrix[i][j]; i-> row; j-> column
        all_tiles = list(pgui.locateAllOnScreen(self.unrevealed_tile))
        self.tile_size = all_tiles[0][2]
        self.height = (len([x for idx, x in enumerate(all_tiles)
                                if x[1] != all_tiles[(idx+1)%len(all_tiles)][1]]))
        self.width = len(all_tiles)//self.height
        #order the tiles to build matrix according to our rule
        tiles_ordered = sorted(all_tiles, key=lambda x: (x[1], x[0]))
        tiles_matrix = [Tile((x[0], x[1], x[0]+self.tile_size, x[1]+self.tile_size)) for x in tiles_ordered]
        tiles_matrix = auxf.reshape(tiles_matrix, self.height, self.width)

        #Update some tile states
        for i, row in enumerate(tiles_matrix):
            for j, tile in enumerate(row):
                tile.tilesNear = auxf.get_adjacents(tiles_matrix, i, j)

        self.board = tiles_matrix

        if self.debug:
            print("Board information complete")
            print("Board stored")
            print(self.__repr__())

    #-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    #Called everytime there's need to get the new board
#    def update_board(self):
#        """Get current board information"""
#
#        #Image processing
#        tiles_0 = ([(0, tuple(map(lambda x: x+1, cords)))
#                    for cords in pgui.locateAllOnScreen(self.blank_tile)])
#
#        tiles_1 = ([(1, cords)
#                    for cords in pgui.locateAllOnScreen(self.tile1)])
#
#        tiles_2 = ([(2, cords)
#                    for cords in pgui.locateAllOnScreen(self.tile2)])
#
#        tiles_3 = ([(3, cords)
#                    for cords in pgui.locateAllOnScreen(self.tile3)])
#
#        tiles_4 = ([(4, cords)
#                    for cords in pgui.locateAllOnScreen(self.tile4)])
#
#        tiles_5 = ([(5, cords)
#                    for cords in pgui.locateAllOnScreen(self.tile5)])
#
#        tiles_6 = ([(6, cords)
#                    for cords in pgui.locateAllOnScreen(self.tile6)])
#
#        tiles_7 = ([(7, cords)
#                    for cords in pgui.locateAllOnScreen(self.tile7)])
#
#        tiles_8 = ([(8, cords)
#                    for cords in pgui.locateAllOnScreen(self.tile8)])
#
#        tiles_bombs = ([("F", cords)
#                        for cords in pgui.locateAllOnScreen(self.flag)])
#
#        tiles_unknown = ([(-1, cords)
#                    for cords in pgui.locateAllOnScreen(self.unrevealed_tile)])
#
#        #Matrix Processing
#        grid = (tiles_0 + tiles_1 + tiles_2 + tiles_3 + tiles_4 + tiles_5 +
#                tiles_6 + tiles_7 + tiles_8 + tiles_bombs + tiles_unknown)
#
#        #order the grid based on positions on screen
#        grid = sorted(grid, key=lambda x: (x[1][1], x[1][0]))
#        #remove coordinates (no longer useful)
#        grid = auxf.filter_board(grid)
#        #reshape grid to matrix form
#        grid = auxf.reshape(grid, self.height, self.width)
#
#        #Board updating
#        for i, line in enumerate(grid):
#            for j, value in enumerate(line):
#                #If it's still a unknown tile, ignore it
#                if value == -1:
#                    continue
#
#                tile = self.board[i][j]
#                #If the value has been changed
#                if True:
#                    #and it's a bomb, update tile states
#                    if value == "F":
#                        tile.hidden = False
#                        tile.linked = False
#                        tile.bomb = True
#                        tile.flagged = True
#                        tile.value = "F"
#
#                    #or isn't a bomb, update tile states
#                    else:
#                        tile.hidden = False
#                        tile.value = value
#
#        #final check-up and update the whole board
#        self.updateBoardInfo()
#
#        #if debugging is activated
#        if self.debug:
#            print("Board update complete")
#            #print grid read
#            print("Board read")
#            auxf.print_grid(grid)
#
#            #print grid stored
#            print("Board stored")
#            print(self.__repr__())

    #-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    #Chooses next targets tiles
    def nextTarget(self, allow_random=True):
        #initial update
        self.updateBoardInfo()

        #if tile has all bombs then all the hidden tiles are safe
        for i, line in enumerate(self.board):
            for j, tile in enumerate(line):
                if not (tile.value is None or tile.bomb or tile.flagged or tile.hidden):
                    #update Tile info
                    tile.updateTileInfo()
                    if tile.bombNear == tile.value:
                        self.targetAllHiddenNear(i, j, False)

        #if tile has the same amount unflagged tiles as they have hidden tiles then all hidden are bombs
        for i, line in enumerate(self.board):
            for j, tile in enumerate(line):
                if not (tile.value is None or tile.bomb):
                    #update tile info
                    tile.updateTileInfo()
                    if tile.hiddenNear != 0 and tile.hiddenNear + tile.bombNear == tile.value:
                        self.targetAllHiddenNear(i, j, True)

        #if there's no targets, check linked tiles
        if len(self.targets) == 0:
            self.get_linkedTiles()

            #if there is no targets yet
            if len(self.targets) == 0 and allow_random:
                self.early_guesses(False)

        #final update
        self.updateBoardInfo()

        #if debugging is activated
        if self.debug:
            print("Targets acquired")
            #print grid stored
            print("Board stored")
            print(self.__repr__())

    #-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    #Update board information
    def updateBoardInfo(self):
        for row in self.board:
            for tile in row:
                tile.updateTileInfo()

    #-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    #Called when all hidden tiles near the given location are either all bombs or all safe
    def targetAllHiddenNear(self, i, j, isBomb):
        tile = self.board[i][j]

        if tile.value is None:
            return

        for adjtile in tile.tilesNear:
            if adjtile.value is None and adjtile.hidden:
                if not adjtile.istarget:
                    adjtile.bomb = isBomb
                    adjtile.linked = False
                    adjtile.istarget = True
                    self.targets.append(adjtile)

    #-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    #Called to click all targets
    def clickTargets(self):
        for target in self.targets:
            #if target is already flagged or is already known then skip
            if target.flagged or not target.hidden:
                target.linked = False
                target.istarget = False
                continue

            targetX, targetY = target.coords

            #if target is a bomb, flag it
            if target.bomb:
                target.istarget = False
                target.flagged = True
                target.linked = False
                target.hidden = False
                target.value = "F"
                pgui.click(targetX, targetY, button="right")
                continue

            #if target is not a bomb, click it
            if not target.bomb:
                target.istarget = False
                target.linked = False
                target.hidden = False
                pgui.click(targetX, targetY, button="left")
                screenshot = pgui.screenshot()
                self.update_section(screenshot, target)
                continue

        #reset targets
        self.targets = []

        #update board information
        self.updateBoardInfo()

        #if debugging is activated
        if self.debug:
            print("Targets knocked down")
            #print grid stored
            print("Board stored")
            print(self.__repr__())

    #-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    #last resource (probability + pure faith)
#    def gambling(self):


    #-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    #get probabilities
#    def get_probabilities(self):

    #-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    #First guesses
    def early_guesses(self, first_guesses):
        #check if any corner is hidden
        corners = 0
        corners += (self.board[0][0].value is None and not self.board[0][0].bomb and self.board[0][0].hidden and first_guesses)
        corners += (self.board[0][self.width-1].value is None and not self.board[0][self.width-1].bomb and self.board[0][self.width-1].hidden and first_guesses)
        corners += (self.board[self.height-1][0].value is None and not self.board[self.height-1][0].bomb and self.board[self.height-1][0].hidden and first_guesses)
        corners += (self.board[self.height-1][self.width-1].value is None and not self.board[self.height-1][self.width-1].bomb and self.board[self.height-1][self.width-1].hidden and first_guesses)

        if not corners:
            #guess randomly
            targetX = np.random.randint(self.height)
            targetY = np.random.randint(self.width)

            while (self.board[targetX][targetY].bomb or not self.board[targetX][targetY].value is None):
                targetX = np.random.randint(self.height)
                targetY = np.random.randint(self.width)

            self.board[targetX][targetY].istarget = True
            self.targets.append(self.board[targetX][targetY])
            print("Random target")
            #if debugging is activated
            if self.debug:
                print("Target acquired, best of luck")
                #print grid stored
                print("Board stored")
                print(self.__repr__())

            return

        #guess on corner
        random = np.random.randint(4)

        if random == 0:
            targetX = 0
            targetY = 0

        if random == 1:
            targetX = 0
            targetY = self.width-1

        if random == 2:
            targetX = self.height-1
            targetY = 0

        if random == 3:
            targetX = self.height-1
            targetY = self.width-1

        while (self.board[targetX][targetY].bomb or self.board[targetX][targetY].value is not None or not self.board[targetX][targetY].hidden):

            random = np.random.randint(4)

            if random == 0:
                targetX = 0
                targetY = 0

            if random == 1:
                targetX = 0
                targetY = self.width-1

            if random == 2:
                targetX = self.height-1
                targetY = 0

            if random == 3:
                targetX = self.height-1
                targetY = self.width-1

        self.board[targetX][targetY].istarget = True
        self.targets.append(self.board[targetX][targetY])
        print("Random target")

        #if debugging is activated
        if self.debug:
            print("Target acquired, best of luck")
            #print grid stored
            print("Board stored")
            print(self.__repr__())

    #-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    #checks linked adjacents tiles that can lead to some conclusion
    #able to identify patterns that happen
    def get_linkedTiles(self):
        for row in self.board:
            for tile in row:
                tile.updateTileInfo()
                if (tile.value is not None and not tile.bomb and not tile.flagged and not tile.hidden):
                    #if tile only has 1 bomb left on the surronding we can't get conclusions on the bombs placements based on the linked tiles, neither if the value of the tile is 1 or 0
                    if (tile.value - tile.bombNear > 1):
                        #checks every adjacent tiles
                        for hiddenTile in tile.hiddenTilesNear:
                            #if that adjacent tile is linked with something, let's try to get some sort of conclusion
                            if hiddenTile.linked:
                                adjacentLinkedTiles = [] #linked tiles that are also adjacent to the tile

                                #for every tile that is linked to this hidden tile
                                for linkedTile in hiddenTile.linkedTiles:
                                    #if that tile is also adjacent to the main tile, add to the list
                                    if linkedTile in tile.hiddenTilesNear:
                                        adjacentLinkedTiles.append(linkedTile)

                                #if there atleast 2 linked tiles adjacent to the main tile, we can get a conclusion by reducing the number of hidden tiles adjacent to the main tile
                                if len(adjacentLinkedTiles) > 1:
                                    #reduce the number of hidden tiles by the number of adjacent linked tiles -1
                                    #if the number of hidden spaces now is equal to the tile value, then all hidden spaces that aren't linked are bombs
                                    if (tile.hiddenNear - (len(adjacentLinkedTiles)-1) == tile.value - tile.bombNear):

                                        for tileHiddenNear in tile.hiddenTilesNear:
                                            #if that tile isn't a adjacent linked tile to the main tile, target it
                                            if (tileHiddenNear not in adjacentLinkedTiles):
                                                tileHiddenNear.istarget = True
                                                tileHiddenNear.bomb = True
                                                tileHiddenNear.linked = False
                                                tileHiddenNear.linkedTiles = []
                                                if tileHiddenNear not in self.targets:
                                                    print("Linked bomb")
                                                    self.targets.append(tileHiddenNear)

                    #if there's only 1 bomb left there's chance of getting a conclusion about safe tiles
                    #if it only has 2 hidden tiles we can't do anything 50/50, if it has more than 3 it's complicated for this method (probability)
                    elif (tile.value - tile.bombNear == 1 and tile.hiddenNear == 3):
                        #checks every adjacent Tile
                        for adjtile in tile.tilesNear:
                            #if adjacent tile also has 1 bomb left
                            #and only 2 hidden tiles, we can try to eliminate possibilities on the main tile
                            if not (adjtile.hidden or adjtile.value is None or adjtile.bomb or adjtile.flagged):
                                if (adjtile.value - adjtile.bombNear == 1 and adjtile.hiddenNear==2):
                                    main_set = set(tile.hiddenTilesNear)
                                    adj_set = set(adjtile.hiddenTilesNear)
                                    diff = main_set - adj_set
                                    #there's only one main tile that isn't connect to this adjacent tile
                                    if len(diff)==1:
                                        for target in diff:
                                            target.istarget = True
                                            target.linked = False
                                            target.linkedTiles = []
                                            if target not in self.targets:
                                                print("Linked safe")
                                                self.targets.append(target)

       #update board information
        self.updateBoardInfo()

    #-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    @staticmethod
    def restart_game():
        restart = "./data/restart.png"
        game_over = "./data/game_over.png"
        game_won = "./data/game_won.png"
        restart = pgui.locateCenterOnScreen(game_over)

        if restart is None:
            restart = pgui.locateCenterOnScreen(game_won)

        if restart is None:
            restart = pgui.locateCenterOnScreen(restart)

        if restart is not None:
            pgui.click(restart)

        else:
            print("Don't hide the game")

    #-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    def check(self):
        if self.dead: #lost
            return 0

        elif pgui.pixel(*list(map(int, self.game_state))) == (0, 0, 0):
            return 1 #there is a change in game state

        return -1

    #-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    def update_section(self, screenshot, tile):
        #flags are automatically updated and identified
        #hidden cells are also identified so it's irrelevant to check them

        tile_colors = [
                       (0, 0, 255), #1
                       (0, 128, 0), #2
                       (255, 0, 0), #3
                       (0, 0, 128), #4
                       (128, 0, 0), #5
                       (0, 128, 128), #6
                       (0, 0, 0), #7
                       (128, 128, 128), #8
                       ]
            #[(255, 255, 255), (255, 0, 0), (0, 0, 0)]
        value = 0
        colors = [c[1] for c in screenshot.crop(tile.rect).getcolors()]
        #print(colors)
        if (255, 0, 0) in colors and colors[-1] == (0, 0, 0):
            self.dead = True #lost the game
            return

        if colors[0] == (255, 255, 255) and colors[-1] == (128, 128, 128): #hidden cell
            #tile.hidden = True
            return

        for i, color in enumerate(tile_colors):
            if color in colors:
                value = i+1 #value of the tile
                break #found the value

        tile.value = value
        tile.istarget = False
        tile.linked = False
        tile.hidden = False
        #if the value is 0, recursively reveal each one around it
        if value==0:

            for adjtile in tile.tilesNear:
                if (adjtile.hidden and not adjtile.bomb and not adjtile.flagged):
                    adjtile.hidden = False
                    adjtile.linked = False
                    adjtile.istarget = False
                    self.update_section(screenshot, adjtile)

    #-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    #add tiles that are connected in atleast one hidden tile to a block
    
    #-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    #get solution for a block
        
        
            
        
