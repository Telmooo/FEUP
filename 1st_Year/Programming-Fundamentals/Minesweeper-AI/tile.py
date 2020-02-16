"""
Minesweeper Tile
"""
class Tile:
    def __init__(self, rect):
        self.rect = rect
        self.coords = ((rect[0]+rect[2])//2, (rect[1]+rect[3])//2)
        self.bomb = False
        self.hidden = True
        self.value = None
        self.hiddenNear = 8
        self.bombNear = 0
        self.tilesNear = []
        self.hiddenTilesNear = []
        self.linked = False
        self.linkedTiles = []
        self.istarget = False
        self.flagged = False
        self.unknown = True
        self.probability = 0

    #-------------------------------------------------------------------------------------------------------------------------
    #Update the tile information
    def updateTileInfo(self):

        #count the number of bombs near
        n = 0
        for adjtile in self.tilesNear:
            if adjtile.bomb or adjtile.flagged:
                n += 1
        self.bombNear = n

        #count the number of hidden tiles near
        n = 0
        for adjtile in self.tilesNear:
            if adjtile.hidden and not adjtile.flagged and not adjtile.bomb and adjtile.value is None:
                n += 1
        self.hiddenNear = n

        #set the array of hidden tiles near
        l = []
        for adjtile in self.tilesNear:
            if adjtile.hidden and not adjtile.flagged and not adjtile.bomb and adjtile.value is None:
                l.append(adjtile)
        self.hiddenTilesNear = l.copy()

        #if a tile only has 1 bomb left in the surrounding, then the set of all hidden tiles remaining can only contain 1 bomb, so all the tiles are linked, if one is a bomb all the others are safe
        if self.value is not None and not self.bomb and not self.flagged:
            if (self.value - self.bombNear) == 1 and self.hiddenNear > 1:
                l = []
                for adjtile in self.tilesNear:
                    if adjtile.hidden and not adjtile.flagged and not adjtile.bomb and adjtile.value is None:
                        l.append(adjtile)

                #linking tiles
                for adjtile in self.tilesNear:
                    if adjtile.hidden and not adjtile.flagged and not adjtile.bomb and adjtile.value is None:
                        adjtile.linked = True
                        adjtile.linkedTiles = l.copy()
