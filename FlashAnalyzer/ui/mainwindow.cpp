#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent),
	  _lastUsedPath(QUrl::fromLocalFile(QDir::home().absolutePath())),
	  _swfFile(nullptr)
{
	_centralWidget = new QWidget;
	_centralWidget->setFixedSize(800,800);

	QScrollArea *scrollCenter = new QScrollArea;
	scrollCenter->setWidget(_centralWidget);

	setCentralWidget(scrollCenter);

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

	QMenu *menuDebug = menuBar()->addMenu("&Debug");
	_actionDebug = new QAction("&Debug Console", this);
	menuDebug->addAction(_actionDebug);

	// CONNECTION
	connect(_actionLoad,  SIGNAL(triggered()), this, SLOT(loadFile()));
	connect(_actionClose, SIGNAL(triggered()), this, SLOT(closeFile()));
	connect(_actionQuit,  SIGNAL(triggered()), this, SLOT(close()));
	connect(_actionDebug, SIGNAL(triggered()), _loggerConsole, SLOT(show()));

	// resize et centre
	adjustSize();
	QPoint center = this->screen()->availableGeometry().center();
	move(center.x() - width()/2, center.y() - height()/2);
	setAttribute(Qt::WA_QuitOnClose, true);
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

		// TODO bidouille
		std::cout << _swfFile->toString() << std::endl;
		unsigned int nbImage = 0;
		unsigned int nbSound = 0;
		unsigned int nbVideo = 0;

		for (Tag::const_iterator itTag = _swfFile->cbegin(); itTag != _swfFile->cend(); ++itTag)
		{
			unsigned int tagCode = (*itTag)->code();
			if ((tagCode == DEFINE_BITS_TAG) ||
				(tagCode == DEFINE_BITS_LOSSLESS_TAG) ||
				(tagCode == DEFINE_BITS_JPEG_2_TAG) ||
				(tagCode == DEFINE_BITS_JPEG_3_TAG) ||
				(tagCode == DEFINE_BITS_LOSSLESS_2_TAG) ||
				(tagCode == DEFINE_BITS_JPEG_4_TAG))
			{
				nbImage++;
			}
			else if (tagCode == DEFINE_SOUND_TAG)
			{
				nbSound++;
			}
			else if (tagCode == DEFINE_VIDEO_STREAM_TAG)
			{
				/*const DefineVideoStreamTag* video = dynamic_cast<const DefineVideoStreamTag*>(*itTag);
				if (video)
				{
					std::cout << "Video: " << video->uid() << " ; codec=" << (uint16_t) video->codecId() << " ; width=" << video->width() << " ; height=" << video->height() << " ; nbFrames=" << video->numFrames() << std::endl;
				}*/
				nbVideo++;
			}
			(*itTag)->print();
		}
		std::cout << "Number of images: " << nbImage << std::endl;
		std::cout << "Number of sound: " << nbSound << std::endl;
		std::cout << "Number of video: " << nbVideo << std::endl;
		if (_swfFile->fileAttributesTag() != nullptr)
		{
			std::cout << "Has metadata: " << _swfFile->fileAttributesTag()->hasMetaData() << std::endl;
			std::cout << "Use network: " << _swfFile->fileAttributesTag()->useNetwork() << std::endl;
		}
	}
}

void MainWindow::closeFile()
{
	if (_swfFile != nullptr)
	{
		delete _swfFile;
		_swfFile = nullptr;
	}
	setWindowFilePath("");
}
