package circuits;

import java.util.Objects;

public class LogicVariable {

    private String name;
    private boolean value;
    private LogicGate logicGate;

    public LogicVariable(String name, boolean value) {
        this.name = name;
       this.value = value;
        this.logicGate = null;
    }

    public LogicVariable(String name) {
        this(name, false);
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public boolean getValue() {
        if (logicGate != null) logicGate.updateOutput();
        return value;
    }

    public void setValue(boolean value) {
        this.value = value;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof LogicVariable)) return false;
        LogicVariable that = (LogicVariable) o;
        return Objects.equals(name, that.name);
    }

    @Override
    public int hashCode() {
        return Objects.hash(name, value);
    }

    public LogicGate getCalculatedBy() {
        return logicGate;
    }

    public void setCalculatedBy(LogicGate logicGate) {
        this.logicGate = logicGate;
    }

    public String getFormula() {
        return logicGate == null ? name : logicGate.getFormula();
    }
}
