import java.util.List;

public class StringRecipe {

    List<StringTransformer> transformerList;

    public StringRecipe(List<StringTransformer> transformerList) {
        this.transformerList = transformerList;
    }

    public void mix(StringDrink drink) {
        for (StringTransformer transformer : transformerList) {
            transformer.execute(drink);
        }
    }
}
