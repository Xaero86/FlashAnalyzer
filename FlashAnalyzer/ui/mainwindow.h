#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTemporaryDir>

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
	virtual ~MainWindow();

public slots:
	void loadFile();
	void closeFile();
	void updateDescription(Tag* tag);
	void addVideoPreview(Tag* tag, QString& name, int index);
	void selectImagePreview(Tag* tag, QString& name, int index);
	void selectVideoPreview(Tag* tag, QString&, int index);

protected slots:
	void cleanTempDir();

signals:
	void tempDirCleaned();

protected:
	void closeEvent(QCloseEvent *) override;

private:
	QTabWidget*       _centralWidget;

	TagsModel*        _tagsModel;
	QTreeView*        _tagsWidget;
	ExtractableModel* _extractableModel;
	ExtractableView*  _extractableWidget;

	LoggerConsole*    _loggerConsole;
	QTextEdit*        _descriptionWidget;
	RawDataWidget*    _rawDataWidget;
	ImagePreview*     _imagePreview;
	VideoPreview*     _videoPreview;

	QAction*        _actionLoad;
	QAction*        _actionClose;
	QAction*        _actionQuit;
	QAction*        _actionDebug;

	QUrl            _lastUsedPath;

	SWFFile*        _swfFile;

	QList<QTemporaryDir*>  _tempDirs;
	QMessageBox*           _cleanMessage;
	QTimer*                _cleanTimer;
};
#endif // MAINWINDOW_H
