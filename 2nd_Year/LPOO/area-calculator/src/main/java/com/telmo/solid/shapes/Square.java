package com.telmo.solid.shapes;

import com.telmo.solid.shapes.AreaShape;

public class Square implements AreaShape {

    private double side;

    public Square(double side) {
        this.side = side;
    }

    public double getSide() {
        return side;
    }

    @Override
    public double getArea() {
        return side * side;
    }
}
