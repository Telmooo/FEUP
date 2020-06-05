package circuits;

import java.util.Arrays;
import java.util.stream.Collectors;

public abstract class LogicGate {

    protected LogicVariable output;
    protected LogicVariable input1;

    public LogicGate(LogicVariable output, LogicVariable input1) throws ColisionException, CycleException {
        this.output = output;
        this.input1 = input1;
    }

    public LogicVariable getOutput() {
        return output;
    }

    public LogicVariable[] getInputs() {
        return new LogicVariable[] { input1 };
    }

    public abstract String getSymbol();

    public abstract void updateOutput();

    protected void verifyInput() throws CycleException {
        for (LogicVariable var : getInputs()) {
            if (var.getCalculatedBy() != null) {
                for (LogicVariable subVar : var.getCalculatedBy().getInputs()) {
                    if (subVar.equals(output)) throw new CycleException("Can't have loopable variables");
                }
            }
        }
    }

    protected void verifyOutput() throws ColisionException {
        LogicVariable output = getOutput();
        if (output.getCalculatedBy() == null)
            getOutput().setCalculatedBy(this);
        else
            throw new ColisionException("Same variable can't be used by multiple gates");
    }

    public String getFormula() {
        return getSymbol() + Arrays.asList(getInputs())
                                .stream()
                                .map(LogicVariable::getFormula)
                                .collect(Collectors.joining(",", "(", ")"));
    }
}
