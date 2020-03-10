import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.List;

public class Party extends Event {

    private List<Event> events;

    public Party(String title, String date, String description) {
        super(title, date, description);
        this.events = new ArrayList<>();
    }


    public void addEvent(Event e) {
        events.add(e);
    }

    @Override
    public int getAudienceCount() {
        int aud =  super.getAudienceCount();
        for (Event event : events) {
            aud += event.getAudienceCount();
        }
        return aud;
    }
}
