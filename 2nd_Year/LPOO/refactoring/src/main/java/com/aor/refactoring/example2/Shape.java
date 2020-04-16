package com.aor.refactoring.example2;

public abstract class Shape {

    private double x;
    private double y;

    public Shape(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public abstract double getArea();

    public abstract double getPerimeter();

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public abstract void draw(GraphicFramework graphics);
}
