import java.util.Stack;

public class StringInverter implements StringTransformer {

    private Stack<String> last_results;

    public StringInverter() {
        last_results = new Stack<>();
    }

    @Override
    public void execute(StringDrink drink) {
        String original = drink.getText();
        String inverted = new String();

        for (int i = drink.getText().length() - 1; i >= 0; i--) {
            inverted += original.charAt(i);
        }
        drink.setText(inverted);
        last_results.push(drink.getText());
    }

    @Override
    public void undo(StringDrink drink) {
        if (last_results.empty()) return;
        String str = last_results.peek();
        if (drink.getText().equals(str)) {
            execute(drink);
            last_results.pop();
        }
    }
}
