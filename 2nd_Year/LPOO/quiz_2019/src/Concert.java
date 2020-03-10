import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public class Concert {

    private String city;
    private String country;
    private String date;
    private List<Act> acts;
    private int nextTicket;

    public Concert(String city, String country, String date) {
        this.city = city;
        this.country = country;
        this.date = date;
        this.acts = new ArrayList<>();
        this.nextTicket = 1;
    }

    public void addAct(Act act) {
        acts.add(act);
    }

    public List<Act> getActs() {
        return acts;
    }

    public String getCountry() {
        return country;
    }

    public String getCity() {
        return city;
    }

    public String getDate() {
        return date;
    }

    public boolean isValid(Ticket ticket) {
        return this.equals(ticket.getConcert());
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Concert concert = (Concert) o;
        return Objects.equals(city, concert.city) &&
                Objects.equals(country, concert.country) &&
                Objects.equals(date, concert.date);
    }

    @Override
    public int hashCode() {
        return Objects.hash(city, country, date);
    }

    public boolean participates(Artist artist) {
        if (acts.contains(artist)) return true;
        for (Act act : acts) {
            if (act instanceof Band) {
                if (((Band) act).containsArtist(artist)) return true;
            }
        }
        return false;
    }

    public int getTicketNumberAndIncrement() {
        return nextTicket++;
    }
}
