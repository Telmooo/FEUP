package com.aor.refactoring.example6;

import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.List;

public class Tree {

    private Date plantedAt;
    private List<Date> appraisalDates;
    private Location location;

    public Tree(Date plantedAt, Location location){
        this.plantedAt = plantedAt;
        this.setLocation(location);
        this.appraisalDates = new ArrayList<>();
    }

    public void setLocation(Location location) {
        this.location = location;
    }

    public String toString() {
        return "Tree planted at " + this.plantedAt.toString() + " in location " + location.toString();
    }

    void addAppraisal(Date appraisalDate) {
        this.appraisalDates.add(appraisalDate);
    }

    public List<Date> getAppraisals(){
        return this.appraisalDates;
    }

    public Location getLocation() {
        return location;
    }

    public Date getPlantedAt() {
        return plantedAt;
    }

    public boolean isNextAppraisalOverdue(){
        Date today = new Date();
        Date latestAppraisalDate = today;

        if (!this.appraisalDates.isEmpty()) {
            latestAppraisalDate = this.appraisalDates.get(0);
        }
        for(Date appraisalDate : this.appraisalDates) {
            if (latestAppraisalDate.before(appraisalDate)) {
                latestAppraisalDate = appraisalDate;
            }
        }
        Calendar calendar = getNextAppraisal(latestAppraisalDate);

        if (isWeekend(calendar)) {
            int day = calendar.get(Calendar.DAY_OF_MONTH);
            calendar.add(Calendar.DAY_OF_MONTH, 1 + (day % 7));
        }

        Date nextAppraisalDate = calendar.getTime();

        return isOverdue(today, nextAppraisalDate);
    }

    public boolean isWeekend(Calendar calendar) {
        int day = calendar.get(Calendar.DAY_OF_WEEK);
        return (day == Calendar.SATURDAY || day == Calendar.SUNDAY);
    }

    public boolean isOverdue(Date today, Date nextAppraisalDate) {
        return nextAppraisalDate.before(today);
    }

    public Calendar getNextAppraisal(Date latestAppraisalDate) {
        Calendar calendar = Calendar.getInstance();
        calendar.setTime(latestAppraisalDate);
        calendar.add(Calendar.MONTH, 3);
        return calendar;
    }
}
