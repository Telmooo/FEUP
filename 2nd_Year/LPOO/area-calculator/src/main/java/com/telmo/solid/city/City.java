package com.telmo.solid.city;

import com.telmo.solid.SumProvider;

import java.util.ArrayList;
import java.util.List;

public class City implements SumProvider {
    private List<House> houses;

    public City(List<House> houses) {
        this.houses = houses;
    }

    public City() {
        houses = new ArrayList<>();
    }

    public void addHouse(House house) {
        houses.add(house);
    }

    @Override
    public double sum() {
        double sum = 0;
        for (House house : houses) {
            sum += house.getArea();
        }
        return sum;
    }
}
