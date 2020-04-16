package com.aor.refactoring.example5;

public class Turtle {
    private int row;
    private int column;
    private int direction;
    private final char[] directions = { 'N', 'E', 'S', 'W' };

    public Turtle(int row, int column, char direction) {
        this.row = row;
        this.column = column;
        this.direction = 0;
        for (int i = 0; i < 4; i++) {
            if (direction == directions[i]) {
                this.direction = i;
                break;
            }
        }
    }

    public int getRow() {
        return row;
    }

    public int getColumn() {
        return column;
    }

    public char getDirection() {
        return directions[direction];
    }

    public void execute(char command) {
        switch (command) {
            case 'L':
                rotateLeft();
                break;
            case 'R':
                rotateRight();
                break;
            case 'F':
                moveForward();
                break;
        }
    }

    private boolean isNorthSouth() {
        return direction % 2 == 0;
    }

    public void moveForward() {
        if (isNorthSouth()) {
            row += direction - 1;
        } else {
            column += -direction + 2;
        }
    }

    public void rotateRight() {
        direction = (direction + 1) % 4;
    }

    public void rotateLeft() {
        direction = (direction + 3) % 4;
    }
}
