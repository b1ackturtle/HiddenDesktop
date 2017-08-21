#ifndef TRAYWIDGET_H
#define TRAYWIDGET_H

#include <QSystemTrayIcon>
#include <QDialog>

class QAction;
class QMenu;

class TrayWidget : public QDialog
{
  Q_OBJECT

public:
  TrayWidget();

private slots:
  void aboutToShowTrayMenu();
  void hideDesktop();
  void showDesktop();

private:
  void createActions();
  void createTrayIcon();

  bool hide;

  QAction *hideAction;
  QAction *showAction;
  QAction *quitAction;

  QSystemTrayIcon *trayIcon;
  QMenu *trayIconMenu;
};

#endif
