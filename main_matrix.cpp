#include <iostream>
#include "Matrix.h"
#include "Matrix.hpp"
#include <sstream>
#include <stdexcept>
#include "string.h"

using namespace std;
using namespace linalg;

int main()
{
    linalg::Matrix<double> m_d = { {1, 2,5}, {3, 4,7} };
    linalg::Matrix<int> m_i = { {1.1, 2.2, 3.3}, {4.4, 5.5, 6.6} };
    linalg::Matrix<short> m_s = m_d - m_i;
    cout << m_s;
    m_i = m_d;
    /*m_s = m_i;
    m_s += m_i;
    m_s -= m_i;
    m_s *= 3.14;
    cout << m_d<<'\n';
    cout << m_i;
    m_d*= m_i;
    cout << m_d;
    m_d=0* m_d;

    cout << m_d << "\n";
    cout << m_i;*/
    if (m_d == m_i) {
        cout << "Matrices are equal\n";
    }
    else {
        cout << "Matrices are not equal\n";
    }
    cout << m_d << endl;
    cout << m_i << endl;
    cout << m_s;

    linalg::Matrix<double> m = { {1}, {2}, {3}, {4}, {5}, {6} };

    return 0;
}
