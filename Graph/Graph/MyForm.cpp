#include "Graph.h"
#include "MyForm.h"
#include <thread>

using namespace System;
using namespace Graph;
using namespace System::Windows::Forms;

void runOpenGL() {
    int argc = 0;
    char* argv = nullptr;
    glutInit(&argc, &argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Graph Visualization");

    glutDisplayFunc(display);
    glOrtho(0.0, 800.0, 600.0, 0.0, -1.0, 1.0);

    glutMainLoop();
}

void runWindowsForms() {
    Application::Run(gcnew MyForm());
}

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "RU");

    // Запускаем GLUT в отдельном потоке
    std::thread glut_thread(runOpenGL);
    glut_thread.detach(); // Отсоединяем поток GLUT

 
    // Запускаем Windows Forms в основном потоке
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    runWindowsForms();

    return 0;
}