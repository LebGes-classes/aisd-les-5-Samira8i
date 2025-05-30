//у меня пятый вариант

#include <iostream>
#include <string>
#include "priority_queue.h"

int main() {
    
    PriorityQueue<int, std::string> queue;

    queue.Enqueue("1", 3);
    queue.Enqueue("2", 1);
    queue.Enqueue("3", 5);
    queue.Enqueue("4", 2);
    queue.Enqueue("5", 4);

    std::cout << "Размер: " << queue.Size() << std::endl;

    std::cout << "Наивысший приоритет: " << queue.Peek() << std::endl;

    std::cout << "\nИзвлечение элемента:\n";
    while (!queue.IsEmpty()) {
        std::cout << "... " << queue.Dequeue() << std::endl;
    }
    return 0;
}