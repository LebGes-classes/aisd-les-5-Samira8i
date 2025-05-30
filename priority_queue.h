//у меня пятый вариант

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <vector>
#include <stdexcept>

template <typename Priority, typename Data>
class PriorityQueue {
private:
    struct Node {
        Data data;       //данные
        Priority priority; // Приоритет элемента
        
        // Конструктор узла
        Node(const Data& d, const Priority& p) : data(d), priority(p) {}
    };

    std::vector<Node> heap; // Вектор для хранения бинарной кучи

    //просеивание элемента вверх по куче 
    void siftUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent].priority >= heap[index].priority) break;
            std::swap(heap[index], heap[parent]);
            index = parent;
        }
    }

    //Просеивание элемента вниз по куче 
    void siftDown(int index) {
        int size = heap.size();
        while (true) {
            int left = 2 * index + 1;  
            int right = 2 * index + 2; 
            int largest = index;       
            if (left < size && heap[left].priority > heap[largest].priority)
                largest = left;
            if (right < size && heap[right].priority > heap[largest].priority)
                largest = right;
            // сраваниваем с потомками (правым и левым)
            if (largest == index) break;
            std::swap(heap[index], heap[largest]);
            index = largest;
        }
    }

public:
    //Добавление элемента в очеред
    void Enqueue(const Data& data, const Priority& priority) {
        // Добавляем элемент в конец 
        heap.emplace_back(data, priority);
        // Просеиваем 
        siftUp(heap.size() - 1);
    }

    //Извлечение элемента с наивысшим приоритетом
    Data Dequeue() {
        if (heap.empty()) throw std::out_of_range("Queue is empty");
        Data result = std::move(heap[0].data);
        heap[0] = std::move(heap.back());
        heap.pop_back();
        // проверка на пустоту и просеивание для восстановление свойств 
        if (!heap.empty()) siftDown(0);
        return result;
    }

    //Просмотр элемента с наивысшим приоритетом без извлечения
    const Data& Peek() const {
        if (heap.empty()) throw std::out_of_range("Очередб пуста");
        return heap[0].data;
    }

    bool IsEmpty() const { return heap.empty(); }


    size_t Size() const { return heap.size(); }
};

#endif 