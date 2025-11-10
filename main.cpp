#include "widget.h"

#include <QApplication>
#include <QScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    // Create two widget instances
    Widget w1;
    Widget w2;
    
    // Get screen geometry to position windows
    QScreen *screen = QApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int screenWidth = screenGeometry.width();
    int screenHeight = screenGeometry.height();
    
    // Calculate window dimensions (split screen in half)
    int windowWidth = screenWidth / 2;
    int windowHeight = 400;  // Fixed height for better visibility
    
    // Position first window on the left
    w1.setGeometry(0, (screenHeight - windowHeight) / 2, windowWidth - 10, windowHeight);
    w1.setWindowTitle("Window 1");
    w1.show();
    
    // Position second window on the right
    w2.setGeometry(windowWidth + 10, (screenHeight - windowHeight) / 2, windowWidth - 10, windowHeight);
    w2.setWindowTitle("Window 2");
    w2.show();
    
    return a.exec();
}
