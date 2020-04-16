package com.telmo.solid.city;

import com.telmo.solid.HasArea;

public class House implements HasArea {

    private double area;

    public House(double area) {
        this.area = area;
    }

    @Override
    public double getArea() {
        return area;
    }
}
