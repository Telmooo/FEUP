import com.googlecode.lanterna.*;
import com.googlecode.lanterna.graphics.TextGraphics;
import com.googlecode.lanterna.screen.Screen;

public class Hero extends Element {

    Hero(int x, int y) {
        super(x, y, "X");
    }

    @Override
    public void draw(TextGraphics graphics) {
        graphics.setForegroundColor(TextColor.Factory.fromString("#FF66E5"));
        graphics.enableModifiers(SGR.BOLD);
        graphics.putString(new TerminalPosition(super.getPosition().getX(), super.getPosition().getY()), super.getElement());
    }

    public Position moveUp() {
        return new Position(super.getPosition().getX(),super.getPosition().getY() - 1);
    }

    public Position moveDown() {
        return new Position(super.getPosition().getX(),super.getPosition().getY() + 1);
    }

    public Position moveRight() {
        return new Position(super.getPosition().getX() + 1, super.getPosition().getY());
    }

    public Position moveLeft() {
        return new Position(super.getPosition().getX() - 1, super.getPosition().getY());
    }
}
