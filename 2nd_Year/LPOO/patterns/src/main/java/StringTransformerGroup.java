import java.util.List;

public class StringTransformerGroup implements StringTransformer {

    List<StringTransformer> transformerList;

    public StringTransformerGroup(List<StringTransformer> transformerList) {
        this.transformerList = transformerList;
    }

    @Override
    public void execute(StringDrink drink) {
        for (StringTransformer transformer : transformerList) {
            transformer.execute(drink);
        }
    }

    @Override
    public void undo(StringDrink drink) {
        for (int i = transformerList.size() - 1; i >= 0; i--) {
            transformerList.get(i).undo(drink);
        }
    }
}
