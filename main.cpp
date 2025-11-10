#include "widget.h"

#include <QApplication>
#include <QScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    // Get screen geometry for window calculations
    QScreen *screen = QApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();  // Use availableGeometry to respect taskbar/menubar
    int screenWidth = screenGeometry.width();
    int screenHeight = screenGeometry.height();
    int screenX = screenGeometry.x();
    int screenY = screenGeometry.y();
    
    // Define spacing and margin constants for better layout
    const int WINDOW_MARGIN = 20;     // Margin from screen edges
    const int WINDOW_SPACING = 15;    // Spacing between windows
    const int WINDOW_COUNT = 2;       // Number of windows to display
    
    // Calculate optimal window dimensions
    // Use 80% of screen height for better proportions
    int windowHeight = static_cast<int>(screenHeight * 0.8);
    // Distribute width evenly with proper spacing
    int totalSpacing = WINDOW_MARGIN * 2 + WINDOW_SPACING * (WINDOW_COUNT - 1);
    int windowWidth = (screenWidth - totalSpacing) / WINDOW_COUNT;
    
    // Calculate vertical position for center alignment
    int windowY = screenY + (screenHeight - windowHeight) / 2;
    
    // Create and position widget instances
    Widget w1;
    int x1 = screenX + WINDOW_MARGIN;
    w1.setGeometry(x1, windowY, windowWidth, windowHeight);
    w1.setWindowTitle("Window 1");
    w1.show();
    
    Widget w2;
    int x2 = x1 + windowWidth + WINDOW_SPACING;
    w2.setGeometry(x2, windowY, windowWidth, windowHeight);
    w2.setWindowTitle("Window 2");
    w2.show();
    
    return a.exec();
}
