package circuits;

public class GateNot extends LogicGate {

    public GateNot(LogicVariable output, LogicVariable input) throws ColisionException, CycleException {
        super(output, input);

        this.verifyInput();
        this.verifyOutput();
        this.updateOutput();
    }

    @Override
    public String getSymbol() {
        return "NOT";
    }

    @Override
    public void updateOutput() {
        output.setValue(!getInputs()[0].getValue());
    }
}
