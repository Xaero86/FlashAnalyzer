#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent),
	  _lastUsedPath(QUrl::fromLocalFile(QDir::home().absolutePath())),
	  _swfFile(nullptr)
{
	_centralWidget = new QTabWidget(this);

	_tagsModel = new TagsModel(this);
	_tagsWidget = new QTreeView();
	_tagsWidget->setSelectionMode(QAbstractItemView::SingleSelection);
	_tagsWidget->setHeaderHidden(true);
	_tagsWidget->setModel(_tagsModel);

	_extractableModel = new ExtractableModel(this);
	_extractableWidget = new ExtractableView();
	_extractableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
	_extractableWidget->setHeaderHidden(true);
	_extractableWidget->setModel(_extractableModel);

	_centralWidget->addTab(_tagsWidget, "Tag tree");
	_centralWidget->addTab(_extractableWidget, "Extractable");

	setCentralWidget(_centralWidget);

	_descriptionWidget = new QTextEdit(this);
	QDockWidget *rightDockWidget = new QDockWidget(this);
	rightDockWidget->setWindowTitle("Description");
	rightDockWidget->setWidget(_descriptionWidget);
	rightDockWidget->setFeatures(QDockWidget::NoDockWidgetFeatures);
	addDockWidget(Qt::RightDockWidgetArea, rightDockWidget);

	_rawDataWidget = new RawDataWidget(this);
	_rawDataWidget->setWindowFlags(_rawDataWidget->windowFlags() | Qt::Window);
	_rawDataWidget->hide();

	_imagePreview = new ImagePreview(this);
	_imagePreview->setWindowFlags(_imagePreview->windowFlags() | Qt::Window);
	_imagePreview->hide();

	_loggerConsole = new LoggerConsole(this);
	_loggerConsole->setWindowFlags(_loggerConsole->windowFlags() | Qt::Window | Qt::WindowStaysOnTopHint);
	_loggerConsole->setMinimumSize(300,200);
	_loggerConsole->setWindowTitle(QCoreApplication::applicationName() + " - Console");

	// MENU FILE
	QMenu *menuFile = menuBar()->addMenu("&File");
	_actionLoad = new QAction("&Open", this);
	menuFile->addAction(_actionLoad);
	_actionClose = new QAction("&Close", this);
	menuFile->addAction(_actionClose);
	menuFile->addSeparator();
	_actionQuit = new QAction("&Quit", this);
	menuFile->addAction(_actionQuit);

	// MENU DEBUG
	QMenu *menuDebug = menuBar()->addMenu("&Debug");
	_actionDebug = new QAction("&Debug Console", this);
	menuDebug->addAction(_actionDebug);

	// CONNECTION
	connect(_actionLoad,  SIGNAL(triggered()), this, SLOT(loadFile()));
	connect(_actionClose, SIGNAL(triggered()), this, SLOT(closeFile()));
	connect(_actionQuit,  SIGNAL(triggered()), this, SLOT(close()));
	connect(_actionDebug, SIGNAL(triggered()), _loggerConsole, SLOT(show()));
	connect(_tagsWidget,  SIGNAL(clicked(const QModelIndex &)), _tagsModel, SLOT(rowSelected(const QModelIndex &)));
	connect(_tagsWidget,  SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(openRawData()));
	connect(_tagsModel,   SIGNAL(tagSelected(Tag*)), this, SLOT(updateDescription(Tag*)));
	connect(_extractableWidget,  SIGNAL(tagSelected(Tag*,QString&)), this, SLOT(updatePreview(Tag*,QString&)));
	connect(_extractableWidget,  SIGNAL(doubleClick(int)), this, SLOT(openPreview(int)));

	connect(_imagePreview,  SIGNAL(leftPress()), _extractableWidget, SLOT(selectPrevious()));
	connect(_imagePreview,  SIGNAL(rightPress()), _extractableWidget, SLOT(selectNext()));
	connect(_imagePreview,  SIGNAL(upPress()), _extractableWidget, SLOT(selectPrevious()));
	connect(_imagePreview,  SIGNAL(downPress()), _extractableWidget, SLOT(selectNext()));

	// resize et centre
	adjustSize();
	QPoint center = this->screen()->availableGeometry().center();
	move(center.x() - width()/2, center.y() - height()/2);
}

void MainWindow::loadFile()
{
	QUrl imageFile = QFileDialog::getOpenFileUrl(this, "Open flash file", _lastUsedPath, "Flash file (*.swf)");
	if (!imageFile.isEmpty())
	{
		closeFile();
		_lastUsedPath = imageFile;
		_swfFile = new SWFFile(_lastUsedPath.toLocalFile().toStdString());

		setWindowFilePath(_lastUsedPath.toLocalFile());

		_tagsModel->setSwfData(_swfFile);
		_extractableModel->setSwfData(_swfFile);

		_descriptionWidget->setText(QString::fromStdString(_swfFile->toString()));
		_rawDataWidget->clear();
	}
}

void MainWindow::closeFile()
{
	if (_swfFile != nullptr)
	{
		_tagsModel->setSwfData(nullptr);
		_extractableModel->setSwfData(nullptr);
		delete _swfFile;
		_swfFile = nullptr;
	}
	setWindowFilePath("");
	_descriptionWidget->clear();
	_rawDataWidget->clear();
}

void MainWindow::updateDescription(Tag* tag)
{
	if (tag == nullptr)
	{
		return;
	}
	_descriptionWidget->setText(QString::fromStdString(tag->tagDescription()));
	_rawDataWidget->setData(tag->data(), tag->dataSize());
}

void MainWindow::openRawData()
{
	_rawDataWidget->show();
}

void MainWindow::updatePreview(Tag* tag, QString& name)
{
	if (tag == nullptr)
	{
		_descriptionWidget->clear();
		return;
	}
	if (tag->isImage())
	{
		_imagePreview->setTagImage(tag, name);
	}
	_descriptionWidget->setText(QString::fromStdString(tag->tagDescription()));
}

void MainWindow::openPreview(int type)
{
	if (type == 0)
	{
		_imagePreview->show();
	}
}
