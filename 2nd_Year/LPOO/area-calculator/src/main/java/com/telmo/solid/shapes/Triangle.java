package com.telmo.solid.shapes;

import com.telmo.solid.shapes.AreaShape;

public class Triangle implements AreaShape {

    private double base;
    private double height;

    public Triangle(double base, double height) {
        this.base = base;
        this.height = height;
    }

    public double getBase() {
        return base;
    }

    public double getHeight() {
        return height;
    }

    @Override
    public double getArea() {
        return base * height / 2.0;
    }
}
