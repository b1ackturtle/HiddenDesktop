#include "traywidget.h"

#include <QAction>
#include <QCoreApplication>
#include <QMenu>
#include <QProcess>

TrayWidget::TrayWidget()
  : hide(false)
{
  createActions();
  createTrayIcon();

  trayIcon->show();
}

void TrayWidget::createActions()
{
  hideAction = new QAction(tr("Hide Desktop Icons"), this);
  connect(hideAction, SIGNAL(triggered()), this, SLOT(hideDesktop()));
  
  showAction = new QAction(tr("Show Desktop Icons"), this);
  connect(showAction, SIGNAL(triggered()), this, SLOT(showDesktop()));

  quitAction = new QAction(tr("&Quit"), this);
  connect(quitAction, SIGNAL(triggered()), this, SLOT(showDesktop()));
  connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
}

void TrayWidget::createTrayIcon()
{
  trayIconMenu = new QMenu(this);
  trayIconMenu->addAction(hideAction);
  trayIconMenu->addAction(showAction);
  trayIconMenu->addSeparator();
  trayIconMenu->addAction(quitAction);

  trayIcon = new QSystemTrayIcon(this);
  trayIcon->setContextMenu(trayIconMenu);
  trayIcon->setIcon(QIcon(":/images/hide.png"));

  connect(trayIconMenu, SIGNAL(aboutToShow()), this, SLOT(aboutToShowTrayMenu()));
}

void TrayWidget::aboutToShowTrayMenu()
{
  trayIconMenu->clear();
  if(!hide) trayIconMenu->addAction(hideAction);
  else trayIconMenu->addAction(showAction);
  trayIconMenu->addSeparator();
  trayIconMenu->addAction(quitAction);
}

void TrayWidget::hideDesktop()
{
  hide = true;

  trayIcon->setIcon(QIcon(":/images/show.png"));

  QProcess proc;
  proc.execute("defaults write com.apple.finder CreateDesktop -boolean false");
  proc.execute("killall Finder");
}

void TrayWidget::showDesktop()
{
  hide = false;

  trayIcon->setIcon(QIcon(":/images/hide.png"));

  QProcess proc;
  proc.execute("defaults write com.apple.finder CreateDesktop -boolean true");
  proc.execute("killall Finder");
}
