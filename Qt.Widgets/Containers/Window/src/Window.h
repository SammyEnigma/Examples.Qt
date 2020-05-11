#pragma once
#include <QCloseEvent>
#include <QFrame>
#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>

namespace Examples {
  class Window1 : public QMainWindow {
    Q_OBJECT
  public:
    Window1() {
      button.setText("Close");
      button.move(10, 10);
      connect(&button, &QPushButton::clicked, this, &Window1::close);

      setCentralWidget(&frame);
      setWindowTitle("Window");
      resize(640, 480);
    }

    void closeEvent(QCloseEvent *event) override {
      event->ignore();
      if (QMessageBox::question(this, "Close Window", "Are you sure you want exit?", QMessageBox::StandardButton::Yes|QMessageBox::StandardButton::No) == QMessageBox::StandardButton::Yes)
        QMainWindow::closeEvent(event);
    }

  private:
    QFrame frame;
    QPushButton button {&frame};
  };
}
