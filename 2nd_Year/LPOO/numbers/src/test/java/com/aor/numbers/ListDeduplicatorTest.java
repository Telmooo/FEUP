package com.aor.numbers;

import com.telmo.lib.Listings;
import org.junit.Test;

import java.util.List;

import static org.junit.Assert.*;

public class ListDeduplicatorTest {

    @Test
    public void deduplicate() {

        class Stub implements IListSorter {
            @Override
            public List<Integer> sort() {
                return Listings.initializeList(Listings.MODE_SEQUENTIAL, 1, 2, 2, 4);
            }
        }

        List<Integer> list = Listings.initializeList(Listings.MODE_SEQUENTIAL, 1, 2, 4, 2, 5);

        List<Integer> expected = Listings.initializeList(Listings.MODE_SEQUENTIAL, 1, 2, 4, 5);

        ListDeduplicator deduplicator = new ListDeduplicator(list);

        ListSorter sorter = new ListSorter(list);
        List<Integer> distinct = deduplicator.deduplicate(sorter);

        assertEquals(expected, distinct);

        list = Listings.initializeList(Listings.MODE_SEQUENTIAL, 1, 2, 4, 2);
        expected = Listings.initializeList(Listings.MODE_SEQUENTIAL, 1, 2, 4);

        deduplicator = new ListDeduplicator(list);
        distinct = deduplicator.deduplicate(new Stub());

        assertEquals(expected, distinct);
    }
}