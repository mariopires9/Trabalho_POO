#include <cstdlib>
#include <ctime>

#include "Interface.h"

using namespace std;

int main() {
    srand(time(NULL));
    Interface *interface;
    interface->trataMenuPrincipal();
    
    return 0;
}



