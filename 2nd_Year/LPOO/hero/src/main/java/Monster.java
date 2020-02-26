import com.googlecode.lanterna.SGR;
import com.googlecode.lanterna.TextColor;
import com.googlecode.lanterna.graphics.TextGraphics;

import java.util.Random;

public class Monster extends Element {

    Monster(int x, int y) {
        super(x, y, "M");
    }

    @Override
    public void draw(TextGraphics graphics) {
        graphics.setForegroundColor(TextColor.Factory.fromString("#004400"));
        graphics.enableModifiers(SGR.BOLD);
        graphics.putString(super.getPosition().getX(), super.getPosition().getY(), super.getElement());
    }

    public Position move() {
        Random random = new Random();
        switch (random.nextInt(4)) {
            case 0:
                return new Position(super.getPosition().getX() - 1, super.getPosition().getY());
            case 1:
                return new Position(super.getPosition().getX() + 1, super.getPosition().getY());
            case 2:
                return new Position(super.getPosition().getX(), super.getPosition().getY() - 1);
            case 3:
                return new Position(super.getPosition().getX(), super.getPosition().getY() + 1);
            default:
                return new Position(super.getPosition().getX(), super.getPosition().getY());
        }
    }
}
