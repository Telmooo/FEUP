import com.googlecode.lanterna.TextCharacter;
import com.googlecode.lanterna.input.KeyStroke;
import com.googlecode.lanterna.input.KeyType;
import com.googlecode.lanterna.screen.Screen;
import com.googlecode.lanterna.screen.TerminalScreen;
import com.googlecode.lanterna.terminal.DefaultTerminalFactory;
import com.googlecode.lanterna.terminal.Terminal;

import javax.swing.*;
import java.io.IOException;

public class Game {

    private Screen screen;
    private Terminal terminal;
    private int x = 10;
    private int y = 10;

    public Game() {
        try {
            terminal = new DefaultTerminalFactory().createTerminal();
            screen = new TerminalScreen(terminal);

            screen.setCursorPosition(null);
            screen.startScreen();
            screen.doResizeIfNecessary();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void draw() throws IOException {
        screen.clear();
        screen.setCharacter(x, y, new TextCharacter('X'));
        screen.refresh();
    }

    public void run() throws IOException {
        draw();
        KeyStroke key = screen.readInput();
        processKey(key);
    }

    private void processKey(KeyStroke key) throws IOException{
        if (key.getKeyType() == KeyType.ArrowUp) {
            y--;
        } else if (key.getKeyType() == KeyType.ArrowDown) {
            y++;
        } else if (key.getKeyType() == KeyType.ArrowLeft) {
            x--;
        } else if (key.getKeyType() == KeyType.ArrowRight) {
            x++;
        } else if (key.getKeyType() == KeyType.Escape) {
            throw new IOException();
        }
    }
}
