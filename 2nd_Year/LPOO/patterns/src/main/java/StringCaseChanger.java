import java.util.Stack;

public class StringCaseChanger implements StringTransformer {

    private Stack<String> last_results;

    public StringCaseChanger() {
        last_results = new Stack<>();
    }

    @Override
    public void execute(StringDrink drink) {
        String original = drink.getText();
        String caseChanged = new String();

        for (char c : original.toCharArray()) {
            if (Character.isUpperCase(c)) caseChanged += Character.toLowerCase(c);
            else                          caseChanged += Character.toUpperCase(c);
        }
        drink.setText(caseChanged);
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
