import java.io.IOException;

public class Application {
    public static void main(String[] args) {
        Game game = new Game();

        try {
            while (true) {
                game.run();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
