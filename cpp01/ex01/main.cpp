#include "Zombie.hpp"

int main(){
    int n = 5;
    Zombie *z = Zombie::zombieHorde(n, "sülo");
    for (int i = 0; i < n; i++)
    {
        z[i].announce();
    }
    delete[] z;
}