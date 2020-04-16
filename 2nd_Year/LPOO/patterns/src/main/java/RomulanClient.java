public class RomulanClient extends AlienClient {

    @Override
    protected OrderingStrategy createOrderingStrategy() {
        return new ImpatientStrategy();
    }
}
