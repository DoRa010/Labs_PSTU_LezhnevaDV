#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int m = 3;

    // Пункт 1
    int n1 = n;
    int res1 = n1++ - m;
    cout << "1) n++ - m = " << res1 << " (n стало " << n1 << ")" << endl;

    // Пункт 2
    int n2 = n;
    int res2 = n2++ + m;
    cout << "2) n++ + m = " << res2 << " (n стало " << n2 << ")" << endl;

    // Пункт 3
    int n3 = n;
    int res3 = n3++ * m;
    cout << "3) n++ * m = " << res3 << " (n стало " << n3 << ")" << endl;

    return 0;
}
