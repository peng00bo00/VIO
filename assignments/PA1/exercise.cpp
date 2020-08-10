#include <Eigen/Core>
#include <sophus/se3.hpp>

using namespace std;

int main() {
    Eigen::Vector3d w;
    w << 0.01, 0.02, 0.03;

    Eigen::Quaterniond q = Eigen::Quaterniond::UnitRandom();
    Eigen::Matrix3d R = q.matrix();

    // update with quaterniond
    Eigen::Quaterniond dq;
    dq.w() = 1;
    dq.vec() = 0.5*w;

    q = q * dq;
    cout << "Update with quaterniond: R = " << endl;
    cout << q.matrix() << endl;

    // update with SO3
    Sophus::SO3d dR = Sophus::SO3d::exp(w);
    R = R * dR.matrix();

    cout << "Update with SO3: R = " << endl;
    cout << R << endl;

    return 0;
}
