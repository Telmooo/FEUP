import java.util.Stack;

public class StringReplacer implements StringTransformer {

    private char from;
    private char to;
    private Stack<String> last_results;

    public StringReplacer(char from, char to) {
        this.from = from;
        this.to = to;
        last_results = new Stack<>();
    }

    @Override
    public void execute(StringDrink drink) {
        drink.setText(drink.getText().replace(from, to));
        last_results.push(drink.getText());
    }

    @Override
    public void undo(StringDrink drink) {
        if (last_results.empty()) return;
        String str = last_results.peek();
        if (drink.getText().equals(str)) {
            drink.setText(str.replace(to, from));
            last_results.pop();
        }
    }
}
