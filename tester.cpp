// g++ -Wall -Wextra tester.cpp -o tester; ./tester

#include "ArrayListDictionary.hpp"
#include <string>


int main() {
    int N = 15;
    ArrayListDictionary<int, int> dict(N);
    try {
        cout << dict.find(33) << " ";
        cout << "ERROR: found something in empty";
    } catch (string e) {
    }
    for (int i = 0; i < N; i++) {
        // add only odd numbers (N, 10*N)
        dict.insert(i*2 + 1, (i*2 + 1) * 10);
        for (int j = 0; j <= (i*2+2); j++) {
            try {
                int val = dict.find(j);
                if (val != (j * 10)) {
                    cout << "ERROR: wrong found value";
                    cout << j << endl;
                    cout << val << endl;
                }
            } catch (string e) {
                if (j % 2 == 1) {
                    cout << "ERROR: should have found something but did not";
                }
            }

        }
    }

    return 0;
}
