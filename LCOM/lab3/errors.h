#ifndef ERRORS_H_INCLUDED
#define ERRORS_H_INCLUDED

enum errors {
    SUCCESS = 0,    /* @brief Sucessful */
    NULL_PTR,       /* @brief Null Pointer Error */
    LCF_ERROR,      /* @brief Error originated on LCF */
    SBCR_ERROR,     /* @brief Error on Subscribing Interrupt */
    UNSBCR_ERROR,   /* @brief Error on Unsubscring Interrupt*/
    READ_ERROR,     /* @brief Error on Reading from Port */
    WRITE_ERROR,    /* @brief Error on Writing to Port */
    TIMEOUT_ERROR,  /* @brief Timeout error */
};

#endif // ERRORS_H_INCLUDED
