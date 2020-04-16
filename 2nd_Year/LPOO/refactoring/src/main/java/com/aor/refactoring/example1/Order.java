package com.aor.refactoring.example1;

import java.util.ArrayList;
import java.util.List;

public class Order {
    private List<OrderLine> lines;

    public Order() {
        lines = new ArrayList<>();
    }

    public void add(Product product, int quantity) {
        lines.add(new OrderLine(product, quantity));
    }

    public boolean isElegibleForFreeDelivery() {
        double total = 0;

        for (OrderLine line : lines)
            total += line.getOrderPrice();

        return total > 100;
    }

    public String printOrder() {
        StringBuffer printBuffer = new StringBuffer();

        double total = 0;
        for (OrderLine line : lines) {
            double current = line.getOrderPrice();
            String str = line.product.getName() + "(x" + line.quantity + "): " + line.getOrderPrice() + "\n";
            printBuffer.append(str);
            total += current;
        }

        printBuffer.append("Total: " + total);

        return printBuffer.toString();
    }
}