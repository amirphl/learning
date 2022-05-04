// https://www.geeksforgeeks.org/arrays-in-c-cpp/

#include<iostream>

int main() {
    int a[3];
    int b[3] = {1, 2, 3};
    int b2[] = {1, 2, 3};
    int c[3] = {};
    int d[3] = {0};
    int e[3] = {1};
    // int f[3] = {[0..1]=3};
    // int g[] = {[0 .. 1] = 3};
    // int *a;
    // int* a;
    // int * a;
    // int*a;

    for (int i = 0; i < 3; i++) {
        std::cout << "a"<< i << ": " << a[i] << std::endl;
        std::cout << "b"<< i << ": " << b[i] << std::endl;
        std::cout << "c"<< i << ": " << c[i] << std::endl;
        std::cout << "d"<< i << ": " << d[i] << std::endl;
        std::cout << "e"<< i << ": " << e[i] << std::endl;
        // std::cout<<f[i]<<std::endl;
        // std::cout<<g[i]<<std::endl;
    }
    std::cout<< "---------------\n";

    // no IndexOutOfBoundsException
    std::cout << "a[10] = " << a[10] << std::endl;
    std::cout<< "---------------\n";

    // compile error in c++, warning in c
    // int arr[2] = { 10, 20, 30, 40, 50 };

    std::cout << "size of int: " << sizeof(int) << std::endl;
    // memory locations
    for (int i = 0; i < 3; i++) {
        printf("Address a[%d] is %p\n", i, &a[i]);
        std::cout << "address a" << i << " : " << &a[i] << std::endl;
    }
    std::cout<< "---------------\n";

    // wow!
    // TODO(amirphl): only works in c++?
    std::cout<< "other way of iteration:\n";
    for (int i = 0; i < 3; i++) {
        std::cout << i[a] << " ";
    }
    std::cout<< "\n---------------\n";

    // https://www.geeksforgeeks.org/difference-pointer-array-c/
    // TODO(amirphl): How does it find that a is 12 bytes?
    std::cout << "array vs pointer: " << sizeof(a)
    << " " << sizeof(a[0]) << std::endl;

    return 0;
}
