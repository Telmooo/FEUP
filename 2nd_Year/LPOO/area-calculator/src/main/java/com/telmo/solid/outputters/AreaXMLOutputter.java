package com.telmo.solid.outputters;

import com.telmo.solid.SumProvider;

public class AreaXMLOutputter {

    private SumProvider sp;

    public AreaXMLOutputter(SumProvider sp) {
        this.sp = sp;
    }

    public String output() {
        return "<area>" + sp.sum() + "</area>";
    }
}
