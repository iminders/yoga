#ifndef ACTIVATION_TANH_H_
#define ACTIVATION_TANH_H_

#include "../config.h"
#include <Eigen/Core>

namespace net
{

    ///
    /// \ingroup Activations
    ///
    /// The tanh activation function
    ///
    class Tanh
    {
    private:
        typedef Eigen::Matrix<Scalar, Eigen::Dynamic, Eigen::Dynamic> Matrix;

    public:
        // a = activation(z) = tanh(z)
        // Z = [z1, ..., zn], A = [a1, ..., an], n observations
        static inline void activate(const Matrix &Z, Matrix &A)
        {
            A.array() = Z.array().tanh();
        }

        static std::string return_type()
        {
            return "Tanh";
        }
    };

} // namespace net

#endif /* ACTIVATION_SIGMOID_H_ */
