function translation2D(obj_matrix, dx, dy) {
    var transl_arr = { 1, 0, dx, 0, 1, dy };
    var transl_matrix = fromArray(transl_arr, 2, 3);
    return multiply(obj_matrix, transl_matrix);
}

function scale2D(object_matrix, Sx, Sy, Sz) {
    var scale_arr = {Sx, 0, 0,
                     0, Sy, 0,
                     0, 0, Sz };

    return multiply(obj_matrix, scale_arr);
}
