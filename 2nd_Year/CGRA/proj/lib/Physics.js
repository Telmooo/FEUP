/**
 * Physics
 */

class Physics {

    /**
     * Gravitational acceleration
     * From y = 10, box must reach the ground in 3 seconds
     * As we don't have weighted objects
     * 0 = 10 + 1/2 * g * (3 ^ 2) -> |g| = 20/9 = 2.2222 unit/(s^2)
     */
    static g = 2.2222;

    static friction(coef) {
        return coef * this.g;
    }

    static millisToSec(millis) {
        return millis / 1000.0;
    }
};
