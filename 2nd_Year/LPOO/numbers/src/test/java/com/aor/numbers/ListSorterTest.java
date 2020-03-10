package com.aor.numbers;

import com.telmo.lib.Listings;

import org.junit.Test;

import java.util.List;

import static org.junit.Assert.*;

public class ListSorterTest {

    @Test
    public void sort() {

        List<Integer> list = Listings.initializeList(Listings.MODE_SEQUENTIAL, 3, 2, 6, 1, 4, 5, 7);

        List<Integer> expected = Listings.initializeList(Listings.MODE_SEQUENTIAL, 1, 2, 3, 4, 5, 6, 7);


        ListSorter sorter = new ListSorter(list);
        List<Integer> sorted = sorter.sort();

        assertEquals(expected, sorted);

        list = Listings.initializeList(Listings.MODE_SEQUENTIAL, 1, 2, 4, 2);

        expected = Listings.initializeList(Listings.MODE_SEQUENTIAL, 1, 2, 2, 4);

        sorter = new ListSorter(list);
        sorted = sorter.sort();

        assertEquals(expected, sorted);
    }
}