#ifndef OPTIMIZER_SGD_H_
#define OPTIMIZER_SGD_H_

#include <Eigen/Core>
#include "../config.h"
#include "../optimizer.h"

namespace xnet
{


///
/// \ingroup Optimizers
///
/// The Stochastic Gradient Descent (SGD) algorithm
///
class SGD: public Optimizer
{
    private:
        typedef Eigen::Matrix<Scalar, Eigen::Dynamic, 1> Vector;
        typedef Vector::ConstAlignedMapType ConstAlignedMapVec;
        typedef Vector::AlignedMapType AlignedMapVec;

    public:
        Scalar m_lrate;
        Scalar m_decay;

        SGD(const Scalar& lrate = Scalar(0.001), const Scalar& decay = Scalar(0)) :
            m_lrate(lrate), m_decay(decay)
        {}

        void update(ConstAlignedMapVec& dvec, AlignedMapVec& vec)
        {
            vec.noalias() -= m_lrate * (dvec + m_decay * vec);
        }
};


} // namespace xnet


#endif /* OPTIMIZER_SGD_H_ */
