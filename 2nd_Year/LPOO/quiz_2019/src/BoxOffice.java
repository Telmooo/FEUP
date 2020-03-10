import java.util.ArrayList;
import java.util.List;

public class BoxOffice {

    public static List<Ticket> buy(Concert concert, int nTickets) throws InvalidTicket {
        List<Ticket> tickets = new ArrayList<>();

        for (int i = 0; i < nTickets; i++) {
            Ticket ticket = new Ticket(concert.getTicketNumberAndIncrement(), concert);
            tickets.add(ticket);
        }

        return tickets;
    }
}
