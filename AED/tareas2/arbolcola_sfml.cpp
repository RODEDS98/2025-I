#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;


class Node {
public:
    int data;
    Node* izq;
    Node* der;

    Node(int v);
    Node(Node* izq, Node* der);
};

Node::Node(int data) {
    this->data = data;
    this->izq = nullptr;
    this->der = nullptr;
}

Node::Node(Node* izq, Node* der) {
    this->data = izq->data + der->data;
    this->izq = izq;
    this->der = der;
}


template<class T>
struct Cola {
    T A[40];
    T* Tail = nullptr;
    T* Head = nullptr;

    bool vacio();
    bool lleno();
    bool push(T a);
    bool pop(T& a);
};

template<class T>
bool Cola<T>::vacio() {
    return (Tail == nullptr);
}

template<class T>
bool Cola<T>::lleno() {
    int dim = sizeof(A) / sizeof(*A);
    if (!vacio()) {
        if (Head < Tail)
            return (Tail - Head == dim - 1);
        else
            return (!(Head - Tail - 1));
    }
    return false;
}

template<class T>
bool Cola<T>::push(T a) {
    int dim = sizeof(A) / sizeof(*A);

    if (vacio()) {
        Head = A;
        Tail = A;
        *Head = a;
        return true;
    }
    if (!lleno()) {
        if (Tail == A + dim - 1)
            Tail = A;
        else
            Tail++;
        *Tail = a;
        return true;
    }
    cout << "Cola llena\n";
    return false;
}

template<class T>
bool Cola<T>::pop(T& a) {
    int dim = sizeof(A) / sizeof(*A);

    if (vacio()) {
        cout << "Cola vacía\n";
        return false;
    }

    a = *Head;
    if (Head == Tail) {
        Tail = nullptr;
        Head = A;
        return true;
    }

    if (Head == A + dim - 1)
        Head = A;
    else
        Head++;

    return true;
}


class Arbol {
public:
    Arbol() { root = nullptr; }

    Node* get_root() { return root; }

    Node* construir(int* A, int* B);
    //void print(Node* n, int nivel = 0);

private:
    Node* root;
};

Node* Arbol::construir(int* A, int* B) {
    Cola<Node*> cola;
    int contador = 0;
    for (int* p = A; p < B; p++) {
        Node* nodo = new Node(*p);
        cola.push(nodo);
        contador++;
    }

    if (contador % 2 != 0){
        Node* nodo = new Node(0);
        cola.push(nodo);
    }
    while (true) {
        Node* a;
        Node* b;

        if (!cola.pop(a)) break;
        if (!cola.pop(b)) {
            root = a;       // este es el último nodo
            return a;
        }

        Node* nodo = new Node(a, b);
        cola.push(nodo);
    }
    return nullptr;
}


//        DIBUJAR 

const float RADIO = 22.f;
const float VSPACE = 80.f;

void dibujarNodo(sf::RenderWindow& win, Node* n, sf::Font& f, float x, float y, float hspace)
{
    if (!n) return;

    // izquierdo
    if (n->izq) {
        float xh = x - hspace;
        float yh = y + VSPACE;
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(x, y)),
            sf::Vertex(sf::Vector2f(xh, yh))
        };
        win.draw(line, 2, sf::Lines);
        dibujarNodo(win, n->izq, f, xh, yh, hspace / 2);
    }

    // derecho
    if (n->der) {
        float xh = x + hspace;
        float yh = y + VSPACE;
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(x, y)),
            sf::Vertex(sf::Vector2f(xh, yh))
        };
        win.draw(line, 2, sf::Lines);
        dibujarNodo(win, n->der, f, xh, yh, hspace / 2);
    }

    // círculo
    sf::CircleShape cir(RADIO);
    cir.setFillColor(sf::Color(255, 140, 0));     
    cir.setOutlineThickness(2);
    cir.setOutlineColor(sf::Color::White);
    cir.setPosition(x - RADIO, y - RADIO);
    win.draw(cir);

    // texto 
    sf::Text txt;
    txt.setFont(f);
    txt.setCharacterSize(18);
    txt.setString(to_string(n->data));
    txt.setFillColor(sf::Color::Black);

    sf::FloatRect b = txt.getLocalBounds();
    txt.setOrigin(b.left + b.width / 2, b.top + b.height / 2);
    txt.setPosition(x, y);

    win.draw(txt);
}


int main() {

    const int dim = 15;
    int Arr[dim] = { 1,3,5,7,9,11,13,15,17,19,21,23,25,27,29 };

    Arbol A;
    A.construir(Arr, Arr + dim);

    // sfml
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Arbol SFML 2.5.1");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf")) {
        cout << "No se pudo cargar la fuente\n";
        return -1;
    }


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(30, 30, 30));

        dibujarNodo(window, A.get_root(), font,
            window.getSize().x / 2.f, 80.f,
            window.getSize().x / 4.f);

        window.display();
    }

    return 0;
}
