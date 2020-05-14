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

    /**
     * Calculate gravitational acceleration for free fall movement
     * From y, box must reach the ground in t seconds
     * As we don't have weighted objects
     * 0 = y + 1/2 * g * (t ^ 2) -> |g| = y/((1/2) * (t ^ 2)) -> |g| = 2 * y / (t ^ 2)
     * For example, for y = 10 and t = 3
     * 0 = 10 + 1/2 * g * (3 ^ 2) -> |g| = 20/9 = 2.2222 unit/(s^2)
     */
    static freeFallingGravity(y, t) {
        return 2 * y / (t * t);
    }
};
