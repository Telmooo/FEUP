package circuits;

public class GateAnd extends LogicGate {

    private LogicVariable input2;

    public GateAnd(LogicVariable output, LogicVariable input1, LogicVariable input2) throws ColisionException, CycleException {
        super(output, input1);
        this.input2 = input2;

        this.verifyInput();
        this.verifyOutput();
        this.updateOutput();
    }

    @Override
    public LogicVariable[] getInputs() {
        return new LogicVariable[] { input1, input2 };
    }

    @Override
    public String getSymbol() {
        return "AND";
    }

    @Override
    public void updateOutput() {
        boolean outValue = true;
        for (LogicVariable var : getInputs()) {
            outValue &= var.getValue();
        }

        output.setValue(outValue);
    }
}
