import com.googlecode.lanterna.TerminalPosition;
import com.googlecode.lanterna.TerminalSize;
import com.googlecode.lanterna.TextColor;
import com.googlecode.lanterna.graphics.TextGraphics;
import com.googlecode.lanterna.input.KeyStroke;
import com.googlecode.lanterna.screen.Screen;
import jdk.nashorn.internal.ir.Terminal;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Arena {
    private int width;
    private int height;
    private Hero hero;
    private List<Wall> walls;
    private List<Coin> coins;
    private List<Monster> monsters;

    Arena(int width, int height) {
        this.width = width;
        this.height = height;
        this.walls = createWalls();
        hero = new Hero(10, 10);
        this.monsters = createMonsters();
        this.coins = createCoins();
    }

    public void draw(TextGraphics graphics) {
        graphics.setBackgroundColor(TextColor.Factory.fromString("#336699"));
        graphics.fillRectangle(new TerminalPosition(0, 0), new TerminalSize(this.width, this.height), ' ');
        hero.draw(graphics);

        for (Wall wall : walls) {
            wall.draw(graphics);
        }

        for (Coin coin : coins) {
            coin.draw(graphics);
        }

        for (Monster monster : monsters) {
            monster.draw(graphics);
        }
    }

    public boolean processKey(KeyStroke key) throws IOException {
        switch (key.getKeyType()) {
            case ArrowDown:
                moveHero(hero.moveDown());
                break;
            case ArrowUp:
                moveHero(hero.moveUp());
                break;
            case ArrowLeft:
                moveHero(hero.moveLeft());
                break;
            case ArrowRight:
                moveHero(hero.moveRight());
                break;
            case Character:
                switch (key.getCharacter()) {
                    case 'q':
                        return false;
                }
                break;
        }
        return true;
    }

    private boolean verifyMonsterCollisions(Position position) {
        for (Monster monster : monsters) {
            if (monster.getPosition().equals(position)) {
                return true;
            }
        }
        return false;
    }

    private boolean verifyMonsterCollisions(Position position, List<Monster> monsters) {
        for (Monster monster : monsters) {
            if (monster.getPosition().equals(position)) {
                return true;
            }
        }
        return false;
    }

    private boolean verifyWallCollisions(Position position) {
        for (Wall wall : walls) {
            if (wall.getPosition().equals(position)) {
                return true;
            }
        }
        return false;
    }

    private boolean verifyWallCollisions(Position position, List<Wall> walls) {
        for (Wall wall : walls) {
            if (wall.getPosition().equals(position)) {
                return true;
            }
        }
        return false;
    }

    private boolean verifyCoinCollisions(Position position) {
        for (Coin coin : coins) {
            if (coin.getPosition().equals(position)) {
                return true;
            }
        }
        return false;
    }

    private boolean verifyCoinCollisions(Position position, List<Coin> coins) {
        for (Coin coin : coins) {
            if (coin.getPosition().equals(position)) {
                return true;
            }
        }
        return false;
    }

    private void moveHero(Position position) {
        moveEntities();
        if (canElementMove(position)) {
            this.hero.setPosition(position);
            retrieveCoin(position);
        }
    }

    private void moveEntities() {
        for (Monster monster : monsters) {
            Position new_position = monster.move();
            if (canElementMove(new_position)) {
                monster.setPosition(new_position);
            }
        }
    }

    private boolean canElementMove(Position position) {
       if(!(position.getX() >= 0 && position.getX() < width && position.getY() >= 0 && position.getY() < height)) return false;

       return !verifyWallCollisions(position);
    }

    private List<Wall> createWalls() {
        List<Wall> walls = new ArrayList<Wall>();

        for (int i = 0; i < width; i++) {
            walls.add(new Wall(i, 0));
            walls.add(new Wall(i, height - 1));
        }

        for (int j = 1; j < height - 1; j++) {
            walls.add(new Wall(0, j));
            walls.add(new Wall(width - 1, j));
        }
        return walls;
    }

    private List<Coin> createCoins() {
        List<Coin> coins = new ArrayList<Coin>();
        Random random = new Random();

        for (int i = 0; i < 5; i++) {
            while (true) {
                int x = random.nextInt(width);
                int y = random.nextInt(height);
                Position pos = new Position(x, y);
                if (hero.getPosition().equals(pos)) continue;

                if (verifyCoinCollisions(pos, coins)) continue;

                if (verifyWallCollisions(pos, walls)) continue;

                coins.add(new Coin(pos.getX(), pos.getY()));
                break;
            }
        }
        return coins;
    }

    private List<Monster> createMonsters() {
        List<Monster> monsters = new ArrayList<Monster>();
        Random random = new Random();

        for (int i = 0; i < 3; i++) {
            while (true) {
                int x = random.nextInt(width);
                int y = random.nextInt(height);
                Position pos = new Position(x, y);
                if (hero.getPosition().equals(pos)) continue;

                if (verifyMonsterCollisions(pos, monsters)) continue;

                if (verifyWallCollisions(pos, walls)) continue;

                monsters.add(new Monster(pos.getX(), pos.getY()));
                break;
            }
        }
        return monsters;
    }

    private boolean retrieveCoin(Position position) {
        return coins.removeIf(coin -> coin.getPosition().equals(position));
    }

    public boolean gameOver() {
        return verifyMonsterCollisions(hero.getPosition());
    }
}
