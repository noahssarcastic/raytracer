//
// Created by ninig on 4/11/2020.
//

#ifndef RAYTRACER_MATRIX_H
#define RAYTRACER_MATRIX_H


class Matrix {
    public:
        double	m[4][4];

        Matrix(void);
        Matrix(const Matrix& mat);
        ~Matrix (void);

        Matrix&
        operator= (const Matrix& rhs);

        Matrix
        operator* (const Matrix& mat) const;

        Matrix
        operator/ (const double d);

        void
        set_identity(void);
};


#endif //RAYTRACER_MATRIX_H
