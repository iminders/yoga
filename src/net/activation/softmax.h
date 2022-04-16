#ifndef ACTIVATION_SOFTMAX_H_
#define ACTIVATION_SOFTMAX_H_

#include "../config.h"
#include <Eigen/Core>

namespace net
{

    ///
    /// \ingroup Activations
    ///
    /// The softmax activation function
    ///
    class Softmax
    {
    private:
        typedef Eigen::Matrix<Scalar, Eigen::Dynamic, Eigen::Dynamic> Matrix;
        typedef Eigen::Array<Scalar, 1, Eigen::Dynamic> RowArray;

    public:
        // a = activation(z) = softmax(z)
        // Z = [z1, ..., zn], A = [a1, ..., an], n observations
        static inline void activate(const Matrix &Z, Matrix &A)
        {
            A.array() = (Z.rowwise() - Z.colwise().maxCoeff()).array().exp();
            RowArray colsums = A.colwise().sum();
            A.array().rowwise() /= colsums;
        }

        static std::string return_type()
        {
            return "Softmax";
        }
    };

} // namespace net

#endif /* ACTIVATION_SOFTMAX_H_ */
