package com.telmo.solid.shapes;

public class Ellipse implements AreaShape {

    private double xRadius;
    private double yRadius;

    public Ellipse(double xRadius, double yRadius) {
        this.xRadius = xRadius;
        this.yRadius = yRadius;
    }

    public double getxRadius() {
        return xRadius;
    }

    public double getyRadius() {
        return yRadius;
    }

    @Override
    public double getArea() {
        return Math.PI * xRadius * yRadius;
    }
}
