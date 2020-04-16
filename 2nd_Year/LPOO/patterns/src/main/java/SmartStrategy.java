import java.util.ArrayList;
import java.util.List;
import java.util.ListIterator;

public class SmartStrategy implements OrderingStrategy {

    private List<StringBar> bars;
    private List<StringRecipe> recipes;
    private List<StringDrink> drinks;

    public SmartStrategy() {
        bars = new ArrayList<>();
        recipes = new ArrayList<>();
        drinks = new ArrayList<>();
    }

    @Override
    public void wants(StringDrink drink, StringRecipe recipe, StringBar bar) {
        if (bar.isHappyHour()) {
            bar.order(drink, recipe);
        } else {
            bars.add(bar);
            recipes.add(recipe);
            drinks.add(drink);
        }
    }

    @Override
    public void happyHourStarted(StringBar bar) {
        ListIterator<StringBar> barIt = bars.listIterator();
        ListIterator<StringRecipe> recipeIt = recipes.listIterator();
        ListIterator<StringDrink> drinkIt = drinks.listIterator();

        while (barIt.hasNext()) {
            StringRecipe r = recipeIt.next();
            StringDrink d = drinkIt.next();
            StringBar b = barIt.next();
            if (b.equals(bar)) {
                bar.order(d, r);
                recipeIt.remove();
                drinkIt.remove();
                barIt.remove();
            }
        }
    }

    @Override
    public void happyHourEnded(StringBar bar) {

    }
}
