#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList<int> ll;

    ll.append(10);
    ll.append(20);
    ll.prepend(5);

    std::cout << "List: " << ll.toString() << std::endl;

    ll.remove(20);
    std::cout << "After deleting 20: " << ll.toString() << std::endl;

    ll.removeAt(0);
    std::cout << "After deleting index 0: " << ll.toString() << std::endl;

    std::cout << "Contains 10? " << (ll.contains(10) ? "Yes" : "No") << std::endl;
    std::cout << "Contains 5? " << (ll.contains(5) ? "Yes" : "No") << std::endl;

    return 0;
}
