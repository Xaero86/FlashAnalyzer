#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "loggerconsole.h"

#include "swffile.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);

public slots:
	void loadFile();
	void closeFile();

private:
	QWidget*        _centralWidget;

	LoggerConsole*  _loggerConsole;

	QAction*        _actionLoad;
	QAction*        _actionClose;
	QAction*        _actionQuit;
	QAction*        _actionDebug;

	QUrl            _lastUsedPath;

	SWFFile*        _swfFile;
};
#endif // MAINWINDOW_H
