#include "utils.h"

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const vector<T> &v) {
    os <<"[";
    for (auto it= v.begin(); it != v.end();it++){
        os<<*it;
        if (it!=v.end()-1) os << ",";
    }
    os<<"]\n";
    return os;
}