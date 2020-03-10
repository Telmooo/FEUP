public class Artist extends Act {

    public Artist(String name, String country) {
        super(name, country);
    }

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        return super.equals(o);
    }
}
