#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "tagsmodel.h"
#include "extractablemodel.h"
#include "extractableview.h"
#include "loggerconsole.h"
#include "rawdatawidget.h"
#include "imagepreview.h"
#include "videopreview.h"

#include "swffile.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);

public slots:
	void loadFile();
	void closeFile();
	void updateDescription(Tag* tag);
	void updatePreview(Tag* tag, QString& name);
	void openPreview(int type);

private:
	QTabWidget*       _centralWidget;

	TagsModel*        _tagsModel;
	QTreeView*        _tagsWidget;
	ExtractableModel* _extractableModel;
	ExtractableView*  _extractableWidget;

	LoggerConsole*  _loggerConsole;

	QTextEdit*      _descriptionWidget;
	RawDataWidget*  _rawDataWidget;
	ImagePreview*   _imagePreview;
	VideoPreview*   _videoPreview;

	QAction*        _actionLoad;
	QAction*        _actionClose;
	QAction*        _actionQuit;
	QAction*        _actionDebug;

	QUrl            _lastUsedPath;

	SWFFile*        _swfFile;
};
#endif // MAINWINDOW_H
