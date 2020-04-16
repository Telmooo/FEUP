package com.aor.refactoring.example4;

import java.util.Objects;

public abstract class Person {

    private final String name;
    private final String phone;

    public Person(String name, String phone) {
        this.name = name;
        this.phone = phone;
    }

    public String getName() {
        return name;
    }

    public String getPhone() {
        return phone;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Worker worker = (Worker) o;
        return Objects.equals(getName(), worker.getName()) &&
                Objects.equals(getPhone(), worker.getPhone());
    }

    @Override
    public int hashCode() {
        return Objects.hash(getName(), getPhone());
    }
}
