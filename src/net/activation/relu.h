#ifndef ACTIVATION_RELU_H_
#define ACTIVATION_RELU_H_

#include <Eigen/Core>
#include "../config.h"

namespace net
{


///
/// \ingroup Activations
///
/// The ReLU activation function
///
class ReLU
{
    private:
        typedef Eigen::Matrix<Scalar, Eigen::Dynamic, Eigen::Dynamic> Matrix;

    public:
        // a = activation(z) = max(z, 0)
        // Z = [z1, ..., zn], A = [a1, ..., an], n observations
        static inline void activate(const Matrix& Z, Matrix& A)
        {
            A.array() = Z.array().cwiseMax(Scalar(0));
        }

        static std::string return_type()
        {
            return "ReLU";
        }
};


} // namespace MiniDNN


#endif /* ACTIVATION_RELU_H_ */
