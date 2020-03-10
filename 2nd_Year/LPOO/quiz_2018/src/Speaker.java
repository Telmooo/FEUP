public class Speaker extends Person {

    public Speaker(String name) {
        super(name);
    }

    public Speaker(String name, int age) {
        super(name, age);
    }

    public int getFee() {
        return 0;
    }

    @Override
    public String toString() {
        return getClass().getName() + " " + getName() + " has a fee value of " + getFee() + ".";
    }
}
