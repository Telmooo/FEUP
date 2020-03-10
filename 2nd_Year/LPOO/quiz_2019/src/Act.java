import java.util.List;
import java.util.Objects;

public abstract class Act {

    protected String name;
    protected String country;

    public Act(String name, String country) {
        this.name = name;
        this.country = country;
    }

    public String getName() {
        return name;
    }

    public String getCountry() {
        return country;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Act)) return false;
        Act act = (Act) o;
        return Objects.equals(name, act.name) &&
                Objects.equals(country, act.country);
    }

    @Override
    public int hashCode() {
        return Objects.hash(name, country);
    }
}
