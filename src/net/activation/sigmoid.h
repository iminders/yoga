#ifndef ACTIVATION_SIGMOID_H_
#define ACTIVATION_SIGMOID_H_

#include "../config.h"
#include <Eigen/Core>

namespace net
{

    ///
    /// \ingroup Activations
    ///
    /// The sigmoid activation function
    ///
    class Sigmoid
    {
    private:
        typedef Eigen::Matrix<Scalar, Eigen::Dynamic, Eigen::Dynamic> Matrix;

    public:
        // a = activation(z) = 1 / (1 + exp(-z))
        // Z = [z1, ..., zn], A = [a1, ..., an], n observations
        static inline void activate(const Matrix &Z, Matrix &A)
        {
            A.array() = Scalar(1) / (Scalar(1) + (-Z.array()).exp());
        }

        static std::string return_type()
        {
            return "Sigmoid";
        }
    };

} // namespace MiniDNN

#endif /* ACTIVATION_SIGMOID_H_ */
