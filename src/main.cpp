#include "view\view.h"
#include "controller\controller.h"

int main()
{
    Controller controller = Controller();
    controller.initialize();
    controller.run();
    controller.~Controller();

    return 0;
}