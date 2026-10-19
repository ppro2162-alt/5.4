#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

bool impl(bool a, bool b) {
    return !a || b;
}

bool equiv(bool a, bool b) {
    return a == b;
}

bool conj(bool a, bool b) {
    return a && b;
}

bool disjunc(bool a, bool b) {
    return a || b;
}

bool xor_(bool a, bool b) {
    return a != b;
}

bool inverse(bool a) {
    return !a;
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    cout << "p q r !A !B F" << endl;

    
    for (int p = 1; p >= 0; --p) {
        for (int q = 1; q >= 0; --q) {
            for (int r = 1; r >= 0; --r) {
                bool a = inverse(conj(impl(q, r), disjunc(p, inverse(r))));
                bool b = inverse(conj(disjunc(p, inverse(q)), impl(r, inverse(p))));
                bool f = equiv(a, b);

                cout << p << " " << q << " " << r << " "
                    << a << " " << b << " " << f << endl;
            }
        }
    }

    return 0;
}