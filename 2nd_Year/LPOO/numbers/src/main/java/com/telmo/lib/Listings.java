package com.telmo.lib;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Listings {

    public static final int MODE_RANDOM = 0;
    public static final int MODE_SEQUENTIAL = 1;

    /**
     * @brief Initializes a list for testing.
     *        The initializing process has different modes:
     *              Mode Random - Initializes a list of random numbers.
     *                  This mode can be customizable with values specified in args.
     *                      arg0 - specifies the size of the list (default is 10).
     *                      arg1 - If arg2 is not specified then:
     *                                  this arguments specifies the upper bound for the numbers generated (exclusive)
     *                             If arg2 is specified then:
     *                                  this argument specifies the lower bound for the numbers generated (inclusive)
     *                      arg2 - upper bound for the numbers generated (exclusive)
     *                      The default range of generation is between 0 (inclusive) and Integer.MAX_VALUE(exclusive)
     *              Mode 1 - Initializes a list with numbers given in args.
     * @param mode Mode to be used
     * @param args Arguments to be used to initialize list. See mode for more instructions.
     * @return List generated
     */
    public static List<Integer> initializeList(int mode, Integer... args) {
        List<Integer> list = new ArrayList<>();
        switch (mode) {
            case MODE_RANDOM:
                int size;
                Integer lowerBound, upperBound;
                switch(args.length) {
                    case 0:
                        size = 10; lowerBound = 0; upperBound = Integer.MAX_VALUE;
                        break;
                    case 1:
                        size = args[0];
                        lowerBound = 0; upperBound = Integer.MAX_VALUE;
                        break;
                    case 2:
                        size = args[0]; upperBound = args[1];
                        lowerBound = 0;
                        break;
                    default:
                        size = args[0]; lowerBound = args[1]; upperBound = args[2];
                        break;
                }
                list = new ArrayList<>();
                Random random = new Random();
                for (int i = 0; i < size; i++) {
                    list.add(random.nextInt(upperBound - lowerBound) + lowerBound);
                }
                break;
            case MODE_SEQUENTIAL:
                list = new ArrayList<>();
                for (Integer arg : args) {
                    list.add(arg);
                }
                break;
        }
        return list;
    }
}
