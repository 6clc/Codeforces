#include <iostream>
#include <functional>

class A{
    public:
    void a(){

    }
};

int main(){
    A x;
    function tmp = std::bind(&A::a, &x);
    tmp();
    return 0;
}