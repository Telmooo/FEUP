package com.aor.numbers;

import com.telmo.lib.Listings;

import org.junit.Test;

import java.util.List;

import static org.junit.Assert.*;

public class ListAggregatorTest {

    @Test
    public void sum() {

        List<Integer> list = Listings.initializeList(Listings.MODE_SEQUENTIAL, 1, 2, 4, 2, 5);

        ListAggregator aggregator = new ListAggregator(list);

        int sum = aggregator.sum();

        assertEquals(14, sum);
    }

    @Test
    public void max() {

        List<Integer> list = Listings.initializeList(Listings.MODE_SEQUENTIAL, 1, 2, 4, 2, 5);

        ListAggregator aggregator = new ListAggregator(list);

        int max = aggregator.max();

        assertEquals(5, max);

        list = Listings.initializeList(Listings.MODE_SEQUENTIAL, -1, -4, -5);

        aggregator = new ListAggregator(list);

        max = aggregator.max();

        assertEquals(-1, max);
    }

    @Test
    public void min() {

        List<Integer> list = Listings.initializeList(Listings.MODE_SEQUENTIAL, 1, 2, 4, 2, 5);

        ListAggregator aggregator = new ListAggregator(list);

        int min = aggregator.min();

        assertEquals(1, min);
    }

    @Test
    public void distinct() {

        class Stub implements IListDeduplicator {
            @Override
            public List<Integer> deduplicate(IListSorter listSorter) {
                return Listings.initializeList(Listings.MODE_SEQUENTIAL, 1, 2, 4);
            }
        }

        List<Integer> list = Listings.initializeList(Listings.MODE_SEQUENTIAL, 1, 2, 4, 2, 5);

        ListAggregator aggregator = new ListAggregator(list);

        int distinct = aggregator.distinct(new ListDeduplicator(list));

        assertEquals(4, distinct);

         list = Listings.initializeList(Listings.MODE_SEQUENTIAL, 1, 2, 4, 2);

        aggregator = new ListAggregator(list);

        distinct = aggregator.distinct(new Stub());

        assertEquals(3, distinct);
    }
}