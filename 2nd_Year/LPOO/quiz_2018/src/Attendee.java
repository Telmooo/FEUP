public class Attendee extends Person {
    public Attendee(String name) {
        super(name);
    }

    public Attendee(String name, int age) {
        super(name, age);
    }

    public boolean hasPaid() {
        return false;
    }

    @Override
    public String toString() {
        return getClass().getName() + " " + getName() + (hasPaid() ? " has" : " hasn't")  + " paid its registration.";
    }
}
