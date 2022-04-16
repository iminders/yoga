
#ifndef NETWORK_H_
#define NETWORK_H_

#include "config.h"
#include "layer.h"
#include "output.h"
#include "rng.h"
#include <Eigen/Core>
#include <map>
#include <vector>

namespace net
{

    class Network
    {
    private:
        typedef Eigen::Matrix<Scalar, Eigen::Dynamic, Eigen::Dynamic> Matrix;
        typedef Eigen::RowVectorXi IntegerVector;
        typedef std::map<std::string, int> MetaInfo;
        RNG m_default_rng;             // Built-in RNG
        RNG &m_rng;                    // Reference to the RNG provided by the user,
                                       // otherwise reference to m_default_rng
        std::vector<Layer *> m_layers; // Pointers to hidden layers
        Output *m_output;              // The output layer

    public:
        Network() : m_default_rng(1),
                    m_rng(m_default_rng),
                    m_output(NULL)
        {
        }
        Network(RNG &rng) : m_default_rng(1),
                            m_rng(rng),
                            m_output(NULL)
        {
        }
        ~Network()
        {
            const int nlayer = num_layers();

            for (int i = 0; i < nlayer; i++)
            {
                delete m_layers[i];
            }

            if (m_output)
            {
                delete m_output;
            }
        }
        int num_layers() const
        {
            return m_layers.size();
        }
    };

}

#endif /* NETWORK_H_ */
