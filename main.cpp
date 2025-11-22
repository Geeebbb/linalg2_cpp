#include "graph.hpp"
using namespace std;
using namespace graph;

// Функция для отрисовки графа в виде ASCII-графики

int main() {
    // Создаем граф
    Graph<int, string, int> gr;
    cout << "Graph empty: " << gr.empty() << endl;

    // Вставляем узлы
    cout << "Insert nodes: (1, one), (2, two), (3, three), (4, four), (5, five), (6, six), (7, seven), (8, eight)" << endl;
    gr.insert(1, "one");
    gr.insert(2, "two");
    gr.insert(3, "three");
    gr.insert(4, "four");
    gr.insert(5, "five");
    gr.insert(6, "six");
    gr.insert(7, "seven");
    gr.insert(8, "eight");

    // Проверяем размер и пустоту графа
    cout << "Graph empty: " << gr.empty() << endl;
    cout << "Graph size: " << gr.size() << endl;

    // Вставляем рёбра
    cout << "Insert edges: ({1, 2}, 12), ({1, 3}, 13), ({2, 3}, 23), ({3, 4}, 34), ({4, 5}, 45), ({5, 6}, 56), ({6, 7}, 67), ({7, 8}, 78)" << endl;
    gr.insert_edge({ 1, 2 }, 12);
    gr.insert_edge({ 1, 3 }, 13);
    gr.insert_edge({ 2, 3 }, 23);
    gr.insert_edge({ 3, 4 }, 34);
    gr.insert_edge({ 4, 5 }, 45);
    gr.insert_edge({ 5, 6 }, 56);
    gr.insert_edge({ 6, 7 }, 67);
    gr.insert_edge({ 7, 8 }, 78);

   
    // Проверка узлов и рёбер
    cout << "Graph[1] empty: " << gr[1].empty() << endl;
    cout << "Graph[1] size (degree out): " << gr.degree_out(1) << endl;
    cout << "Graph[1] value: " << gr[1] << endl;

    cout << "Graph[2] size (degree in): " << gr.degree_in(2) << endl;
    cout << "Graph[3] size (degree in): " << gr.degree_in(3) << endl;
    cout << "Graph[3] size (degree out): " << gr.degree_out(3) << endl;

    // Проверка наличия петель
    cout << "Graph[1] loop: " << gr.loop(1) << endl;
    cout << "Graph[3] loop: " << gr.loop(3) << endl;

    // Вставка петли
    cout << "Insert edge ({1, 1}, 11)" << endl;
    gr.insert_edge({ 1, 1 }, 11);
    cout << "Graph[1] loop: " << gr.loop(1) << endl;

    // Проверка методов at и operator[]
    try {
        cout << "Graph at 2: " << gr.at(2) << endl;
    }
    catch (const std::exception& e) {
        cout << e.what() << endl;
    }
    cout << "Graph[3]: " << gr[3] << endl;

    // Проверка удаления узла
    cout << "Delete node 2" << endl;
    gr.delete_node(2);
    cout << "Graph size after deleting node 2: " << gr.size() << endl;
    try {
        cout << "Graph at 2: " << gr.at(2) << endl;
    }
    catch (const std::exception& e) {
        cout << e.what() << endl;
    }

    // Проверка удаления ребра
    cout << "Delete edge ({1, 3})" << endl;
    gr.delete_edge({ 1, 3 });
    cout << "Graph[1] size (degree out) after deleting edge (1, 3): " << gr.degree_out(1) << endl;

    // Проверка swap
    Graph<int, string, int> gr2;
    gr2.insert(10, "ten");
    gr2.insert(20, "twenty");

    cout << "Swapping graphs" << endl;
    swap(gr, gr2);

    cout << "Graph size after swap: " << gr.size() << endl;
    cout << "Graph2 size after swap: " << gr2.size() << endl;

    // Проверка clear и пустоты
    gr2.clear();
    cout << "Graph2 empty after clear: " << gr2.empty() << endl;

    return 0;
}
