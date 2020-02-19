import com.googlecode.lanterna.TextCharacter;
import com.googlecode.lanterna.screen.Screen;
import com.googlecode.lanterna.screen.TerminalScreen;
import com.googlecode.lanterna.terminal.DefaultTerminalFactory;
import com.googlecode.lanterna.terminal.Terminal;

import java.io.IOException;

public class Application {
    public static void main(String[] args) {
        try {
            Terminal terminal = new DefaultTerminalFactory().createTerminal();
            Screen screen = new TerminalScreen(terminal);

            screen.setCursorPosition(null);
            screen.startScreen();
            screen.doResizeIfNecessary();

            screen.clear();

            String s = "QUERO MORRER";
            int posX = 10, posY = 10;
            for (int i = 0; i < s.length(); i++) {
                screen.setCharacter(posX, posY, new TextCharacter(s.charAt(i)));
                screen.refresh();
                posX += 1;
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
