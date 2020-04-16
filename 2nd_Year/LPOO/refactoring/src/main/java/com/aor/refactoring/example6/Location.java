package com.aor.refactoring.example6;

import java.util.Objects;

public class Location {
    private String latitude;
    private String longitude;
    private String name;

    public Location(String latitude, String longitude, String name) {
        this.latitude = latitude;
        this.longitude = longitude;
        this.name = name;
    }

    public String getLatitude() {
        return latitude;
    }

    public String getLongitude() {
        return longitude;
    }

    public String getName() {
        return name;
    }

    @Override
    public String toString() {
        return latitude + "," + longitude + " (" + name + ")";
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Location)) return false;
        Location location = (Location) o;
        return Objects.equals(latitude, location.latitude) &&
                Objects.equals(longitude, location.longitude) &&
                Objects.equals(name, location.name);
    }

    @Override
    public int hashCode() {
        return Objects.hash(latitude, longitude, name);
    }
}