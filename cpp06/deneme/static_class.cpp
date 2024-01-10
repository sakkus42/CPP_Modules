#include <iostream>
#include <exception>

class Example {
    private:
    public:
        int unit_x:2;
        static int x;
        static void setX(int y) {
            x = y;
        }
        int getX() {
            return (this->x);
        };
};

int Example::x = 4;

int main() {
    Example obj, obj2;
    std::cout <<  obj2.unit_x << std::endl;
    std::cout <<  obj.getX() << std::endl;
    obj2.setX(3);
    std::cout <<  obj.getX() << std::endl;
}