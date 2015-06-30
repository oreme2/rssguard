// This file is part of RSS Guard.
//
// Copyright (C) 2011-2015 by Martin Rotter <rotter.martinos@gmail.com>
//
// RSS Guard is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// RSS Guard is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with RSS Guard. If not, see <http://www.gnu.org/licenses/>.

#ifndef FORMMAIN_H
#define FORMMAIN_H

#include "ui_formmain.h"

#include <QMainWindow>
#include <QUrl>


class StatusBar;

class FormMain : public QMainWindow {
    Q_OBJECT

    friend class TabWidget;
    friend class FeedMessageViewer;
    friend class MessagesView;
    friend class FeedsView;
    friend class MessagesToolBar;

  public:
    // Constructors and destructors.
    explicit FormMain(QWidget *parent = 0, Qt::WindowFlags f = 0);
    virtual ~FormMain();

    // Returns menu for the tray icon.
    inline QMenu *trayMenu() {
      return m_trayMenu;
    }

    // Returns global tab widget.
    inline TabWidget *tabWidget() {
      return m_ui->m_tabWidget;
    }

    // Access to statusbar.
    inline StatusBar *statusBar() {
      return m_statusBar;
    }

    // Returns list of all globally available actions.
    // NOTE: This is used for setting dynamic shortcuts
    // for given actions.
    QList<QAction*> allActions();

    // Loads/saves visual state of the application.
    void loadSize();
    void saveSize();

  protected:
    // Creates all needed menus and sets them up.
    void prepareMenus();

    // Creates needed connections for this window.
    void createConnections();

    // Event handler reimplementations.
    void changeEvent(QEvent *event);

    // Sets up proper icons for this widget.
    void setupIcons();

  public slots:
    // Displays window on top or switches its visibility.
    void display();

    // Switches visibility of main window.
    void switchVisibility(bool force_hide = false);

    // Turns on/off fullscreen mode
    void switchFullscreenMode();

    // Switches visibility of main menu.
    void switchMainMenu();

  protected slots:
    // Loads web browser menu if user selects to change tabs.
    void loadWebBrowserMenu(int index);

    // Displays various dialogs.
    void exportFeeds();
    void importFeeds();
    void backupDatabaseSettings();
    void restoreDatabaseSettings();
    void showSettings();
    void showAbout();
    void showUpdates();
    void showWiki();
    void reportABugOnGitHub();
    void reportABugOnBitBucket();
    void donate();

  private:
    Ui::FormMain *m_ui;
    QMenu *m_trayMenu;
    StatusBar *m_statusBar;
};

#endif // FORMMAIN_H