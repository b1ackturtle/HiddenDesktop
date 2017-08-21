#include <QtWidgets/QApplication>
#include <QtWidgets/QSystemTrayIcon>
#include <QMessageBox>

#include "traywidget.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  if (!QSystemTrayIcon::isSystemTrayAvailable()) {
    QMessageBox::critical(0, QObject::tr("Systray"),
			  QObject::tr("I couldn't detect any system tray "
				      "on this system."));
    return 1;
  }
  QApplication::setQuitOnLastWindowClosed(false);

  TrayWidget TrayWidget;
  return app.exec();
}
