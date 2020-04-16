/**
 * Physics
 */

class Physics {

    /** Gravitational acceleration */
    static g = 9.834;

    static friction(coef) {
        return coef * this.g;
    }
};
