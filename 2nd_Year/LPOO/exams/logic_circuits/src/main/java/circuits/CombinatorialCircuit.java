package circuits;

import java.util.HashSet;
import java.util.Set;

public class CombinatorialCircuit {

    private Set<LogicVariable> vars;

    public CombinatorialCircuit() {
        this.vars = new HashSet<>();
    }

    public boolean addVariable(LogicVariable var) {
        return vars.add(var);
    }

    public LogicVariable getVariableByName(String name) {
        LogicVariable ret = null;
        for (LogicVariable var : vars)
            if (var.getName().equals(name)) {
                ret = var;
                break;
            }
        return ret;
    }
}
