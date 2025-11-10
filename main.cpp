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
    
    // Calculate window dimensions (split screen in half with proper spacing)
    int windowWidth = screenWidth / 2 - 15;  // Account for margins and gap
    int windowHeight = screenHeight * 2 / 3;  // Use 2/3 of screen height for better proportions
    
    // Calculate vertical centering
    int yPosition = (screenHeight - windowHeight) / 2;
    
    // Position first window on the left with margin
    w1.setGeometry(10, yPosition, windowWidth, windowHeight);
    w1.setWindowTitle("Window 1");
    w1.show();
    
    // Position second window on the right with margin
    w2.setGeometry(screenWidth / 2 + 5, yPosition, windowWidth, windowHeight);
    w2.setWindowTitle("Window 2");
    w2.show();
    
    return a.exec();
}
