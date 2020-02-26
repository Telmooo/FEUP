import com.googlecode.lanterna.graphics.TextGraphics;

public abstract class Element {
    private Position position;
    private String element;

    Element(int x, int y, String element) {
        this.position = new Position(x, y);
        this.element = element;
    }

    public Position getPosition() {
        return this.position;
    }

    public void setPosition(Position position) {
        this.position = position;
    }

    public String getElement() {
        return this.element;
    }

    abstract void draw(TextGraphics graphics);
}
