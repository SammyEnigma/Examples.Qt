#pragma once
#include <QApplication>
#include <QFrame>
#include <QMainWindow>
#include <QLabel>
#include <QScreen>

namespace Examples {
  #if defined(__APPLE__)
  inline int pointsToNativeFontGraphicsUntit(int size) {
    return static_cast<float>(size) /QApplication::primaryScreen()->logicalDotsPerInch() * 96.0f;  // font is in pixels and not in points
  }
  #else
  inline int pointsToNativeFontGraphicsUntit(int size) {
    return size;  // font is in points
  }
  #endif

  class Window1 : public QMainWindow {
  public:
    Window1() {
      label1.setText("Hello, World!");
      QPalette palette;
      palette.setColor(QPalette::WindowText, Qt::GlobalColor::darkGreen);
      label1.setPalette(palette);
      label1.setFont({label1.font().family(), pointsToNativeFontGraphicsUntit(34), QFont::Bold, true});
      label1.setAlignment(Qt::AlignCenter | Qt::AlignVCenter);
      label1.setWordWrap(true);

      setCentralWidget(&label1);
      setWindowTitle("Hello world (label)");
      resize(300, 300);
    }

  private:
    QLabel label1 {this};
  };
}
