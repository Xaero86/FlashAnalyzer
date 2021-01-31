#include "mainwindow.h"

#include "definevideostreamtag.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent),
	  _lastUsedPath(QUrl::fromLocalFile(QDir::home().absolutePath())),
	  _swfFile(nullptr),
	  _tempDirs(),
	  _cleanMessage(nullptr),
	  _cleanTimer(nullptr)
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

	_imagePreview = new ImagePreview();
	_imagePreview->setWindowFlags(_imagePreview->windowFlags() | Qt::Window);
	_imagePreview->hide();

	_videoPreview = new VideoPreview();
	_videoPreview->setWindowFlags(_imagePreview->windowFlags() | Qt::Window);
	_videoPreview->hide();

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
	connect(_tagsWidget,  SIGNAL(doubleClicked(const QModelIndex &)), _rawDataWidget, SLOT(show()));
	connect(_tagsModel,   SIGNAL(tagSelected(Tag*)), this, SLOT(updateDescription(Tag*)));
	connect(_extractableWidget,  SIGNAL(imageSelected(Tag*,QString&,int)), this, SLOT(selectImagePreview(Tag*, QString&, int)));
	connect(_extractableWidget,  SIGNAL(videoSelected(Tag*,QString&,int)), this, SLOT(selectVideoPreview(Tag*, QString&, int)));
	connect(_extractableWidget,  SIGNAL(imagePreview()), _imagePreview, SLOT(show()));
	connect(_extractableWidget,  SIGNAL(videoPreview()), _videoPreview, SLOT(show()));
	connect(_extractableModel,   SIGNAL(newVideo(Tag*,QString&,int)), this, SLOT(addVideoPreview(Tag*,QString&,int)));

	connect(_imagePreview,  SIGNAL(imageChanged(int)), _extractableWidget, SLOT(selectImage(int)));
	connect(_videoPreview,  SIGNAL(videoChanged(int)), _extractableWidget, SLOT(selectVideo(int)));

	// resize et centre
	adjustSize();
	QPoint center = this->screen()->availableGeometry().center();
	move(center.x() - width()/2, center.y() - height()/2);
}

MainWindow::~MainWindow()
{
	closeFile();
}

void MainWindow::loadFile()
{
	QUrl imageFile = QFileDialog::getOpenFileUrl(this, "Open flash file", _lastUsedPath, "Flash file (*.swf)");
	if (!imageFile.isEmpty() && imageFile.isLocalFile())
	{
		closeFile();

		QFileInfo fileInfo(imageFile.toLocalFile());
		_lastUsedPath = QUrl::fromLocalFile(fileInfo.dir().path());
		_swfFile = new SWFFile(imageFile.toLocalFile().toStdString());

		setWindowFilePath(imageFile.toLocalFile());

		_tempDirs.append(new QTemporaryDir());
		_tagsModel->setSwfData(_swfFile);
		_extractableModel->setSwfData(_swfFile);
		_extractableWidget->setDefaultUrl(_lastUsedPath);

		_descriptionWidget->setText(QString::fromStdString(_swfFile->toString()));
	}
}

void MainWindow::closeFile()
{
	if (_swfFile != nullptr)
	{
		_imagePreview->setTagImage();
		_videoPreview->clearPlaylist();
		_tagsModel->setSwfData(nullptr);
		_extractableModel->setSwfData(nullptr);
		delete _swfFile;
		_swfFile = nullptr;
		if (_tempDirs.last()->remove())
		{
			delete _tempDirs.takeLast();
		}
	}
	setWindowFilePath("");
	_descriptionWidget->clear();
	_rawDataWidget->clear();
	_imagePreview->hide();
	_videoPreview->hide();
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

void MainWindow::addVideoPreview(Tag* tag, QString& name, int index)
{
	DefineVideoStreamTag* videoTag = dynamic_cast<DefineVideoStreamTag*>(tag);
	if (videoTag)
	{
		QDir dir = _tempDirs.last()->path();
		videoTag->createVideoFile(dir, name);
		_videoPreview->addVideo(index, videoTag->getVideoFile());
		_videoPreview->resize(videoTag->width(), videoTag->height());
	}
}

void MainWindow::selectImagePreview(Tag* tag, QString& name, int index)
{
	if (tag == nullptr)
	{
		_descriptionWidget->clear();
		return;
	}
	if (tag->isImage())
	{
		_imagePreview->setTagImage(tag, name, index);
	}
	_descriptionWidget->setText(QString::fromStdString(tag->tagDescription()));
}

void MainWindow::selectVideoPreview(Tag* tag, QString&, int index)
{
	if (tag == nullptr)
	{
		_descriptionWidget->clear();
		return;
	}
	if (tag->isVideo())
	{
		_videoPreview->selectVideo(index);
	}
	_descriptionWidget->setText(QString::fromStdString(tag->tagDescription()));
}

void MainWindow::closeEvent(QCloseEvent *)
{
	closeFile();
	if (_tempDirs.size() > 0)
	{
		_cleanTimer = new QTimer(this);
		connect(_cleanTimer, SIGNAL(timeout()), this, SLOT(cleanTempDir()));
		_cleanTimer->start(1000);

		_cleanMessage = new QMessageBox(this);
		_cleanMessage->setText("Cleaning temporary ressources");
		_cleanMessage->setInformativeText(QCoreApplication::applicationName() + " folders in " + QDir::tempPath());
		_cleanMessage->setStandardButtons(QMessageBox::Cancel);
		connect(this, SIGNAL(tempDirCleaned()), _cleanMessage, SLOT(reject()));

		_cleanMessage->exec();
	}
}

void MainWindow::cleanTempDir()
{
	QMutableListIterator<QTemporaryDir*> it(_tempDirs);
	while (it.hasNext())
	{
		QTemporaryDir* temp = it.next();
		if (temp->remove())
		{
			it.remove();
			delete temp;
		}
	}
	if (_tempDirs.size() == 0)
	{
		_cleanTimer->stop();
		emit tempDirCleaned();
	}
}
