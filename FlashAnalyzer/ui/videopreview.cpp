#include "videopreview.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStyle>

VideoPreview::VideoPreview(QWidget *parent)
	: QWidget(parent)
{
	setBackgroundRole(QPalette::Base);
	setAutoFillBackground(true);

	_videoWidget = new QVideoWidget(this);
	_videoWidget->setAspectRatioMode(Qt::KeepAspectRatio);

	_mediaPlayer = new QMediaPlayer(nullptr, QMediaPlayer::VideoSurface);
	_mediaPlayer->setVideoOutput(_videoWidget);
	_mediaPlayer->setVolume(0);

	_mediaPlaylist = new QMediaPlaylist(_mediaPlayer);
	_mediaPlaylist->setPlaybackMode(QMediaPlaylist::Loop);
	_mediaPlayer->setPlaylist(_mediaPlaylist);

	_toolbar = new QWidget(this);
	_toolbar->setGeometry(0,0,250,60);

	_playButton = new QPushButton;
	_playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
	_playButton->setFocusPolicy(Qt::NoFocus);
	_nextButton = new QPushButton;
	_nextButton->setIcon(style()->standardIcon(QStyle::SP_MediaSkipForward));
	_nextButton->setFocusPolicy(Qt::NoFocus);
	_prevButton = new QPushButton;
	_prevButton->setIcon(style()->standardIcon(QStyle::SP_MediaSkipBackward));
	_prevButton->setFocusPolicy(Qt::NoFocus);

	_loopCheckBox = new QCheckBox("&Loop");
	_loopCheckBox->setChecked(true);
	_loopCheckBox->setFocusPolicy(Qt::NoFocus);

	_allRadio = new QRadioButton("&All");
	_allRadio->setChecked(true);
	_allRadio->setFocusPolicy(Qt::NoFocus);
	_currentRadio = new QRadioButton("&Current only");
	_currentRadio->setFocusPolicy(Qt::NoFocus);

	QVBoxLayout* vRadioLayout = new QVBoxLayout;
	vRadioLayout->addWidget(_allRadio);
	vRadioLayout->addWidget(_currentRadio);

	QHBoxLayout* hToolLayout = new QHBoxLayout();
	hToolLayout->addWidget(_prevButton);
	hToolLayout->addWidget(_playButton);
	hToolLayout->addWidget(_nextButton);
	hToolLayout->addStretch();
	hToolLayout->addWidget(_loopCheckBox);
	hToolLayout->addLayout(vRadioLayout);
	_toolbar->setLayout(hToolLayout);
	_toolbar->hide();

	QHBoxLayout* hLayout = new QHBoxLayout(this);
	hLayout->setContentsMargins(0,0,0,0);
	hLayout->addWidget(_videoWidget);

	setLayout(hLayout);
	setMinimumSize(250,200);

	connect(_mediaPlaylist, SIGNAL(currentIndexChanged(int)), this, SLOT(handleIndexChanged(int)));
	connect(_mediaPlaylist, SIGNAL(currentMediaChanged(const QMediaContent &)), this, SLOT(handleMediaChanged(const QMediaContent &)));
	connect(_mediaPlayer,   SIGNAL(stateChanged(QMediaPlayer::State)), this, SLOT(handlePlayerStateChanged(QMediaPlayer::State)));
	connect(_playButton,    SIGNAL(clicked()), this, SLOT(handlePlayPause()));
	connect(_nextButton,    SIGNAL(clicked()), this, SLOT(nextVideo()));
	connect(_prevButton,    SIGNAL(clicked()), this, SLOT(previousVideo()));
	connect(_allRadio,      SIGNAL(clicked()), this, SLOT(handlePlaybackMode()));
	connect(_currentRadio,  SIGNAL(clicked()), this, SLOT(handlePlaybackMode()));
	connect(_loopCheckBox,  SIGNAL(clicked()), this, SLOT(handlePlaybackMode()));
}

void VideoPreview::clearPlaylist()
{
	hide();
	_mediaPlayer->stop();
	_mediaPlaylist->clear();
}

void VideoPreview::addVideo(int pos, const QMediaContent &video)
{
	_mediaPlaylist->insertMedia(pos, video);
}

void VideoPreview::selectVideo(int pos)
{
	_mediaPlaylist->setCurrentIndex(pos);
}

void VideoPreview::nextVideo()
{
	if (_mediaPlaylist->playbackMode() == QMediaPlaylist::CurrentItemInLoop)
	{
		_mediaPlaylist->setPlaybackMode(QMediaPlaylist::Loop);
		_mediaPlaylist->next();
		_mediaPlaylist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
	}
	else if (_mediaPlaylist->playbackMode() == QMediaPlaylist::CurrentItemOnce)
	{
		_mediaPlaylist->setPlaybackMode(QMediaPlaylist::Sequential);
		_mediaPlaylist->next();
		_mediaPlaylist->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
	}
	else
	{
		_mediaPlaylist->next();
	}
}

void VideoPreview::previousVideo()
{
	if (_mediaPlaylist->playbackMode() == QMediaPlaylist::CurrentItemInLoop)
	{
		_mediaPlaylist->setPlaybackMode(QMediaPlaylist::Loop);
		_mediaPlaylist->previous();
		_mediaPlaylist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
	}
	else if (_mediaPlaylist->playbackMode() == QMediaPlaylist::CurrentItemOnce)
	{
		_mediaPlaylist->setPlaybackMode(QMediaPlaylist::Sequential);
		_mediaPlaylist->previous();
		_mediaPlaylist->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
	}
	else
	{
		_mediaPlaylist->previous();
	}
}

void VideoPreview::handleIndexChanged(int position)
{
	emit videoChanged(position);
}

void VideoPreview::handleMediaChanged(const QMediaContent &content)
{
	if (!content.isNull())
	{
		setWindowFilePath(content.request().url().fileName());
	}
}

void VideoPreview::handlePlayerStateChanged(QMediaPlayer::State state)
{
	switch (state) {
	case QMediaPlayer::StoppedState:
		_playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
		_videoWidget->hide();
		break;
	case QMediaPlayer::PlayingState:
		_playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
		_videoWidget->show();
		break;
	case QMediaPlayer::PausedState:
		_playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
		_videoWidget->show();
		break;
	}
}

void VideoPreview::handlePlayPause()
{
	if (_mediaPlayer->state() == QMediaPlayer::PlayingState)
	{
		_mediaPlayer->pause();
	}
	else
	{
		_mediaPlayer->play();
	}
}

void VideoPreview::handlePlaybackMode()
{
	if (_loopCheckBox->isChecked())
	{
		if (_allRadio->isChecked())
		{
			_mediaPlaylist->setPlaybackMode(QMediaPlaylist::Loop);
		}
		else
		{
			_mediaPlaylist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
		}
	}
	else
	{
		if (_allRadio->isChecked())
		{
			_mediaPlaylist->setPlaybackMode(QMediaPlaylist::Sequential);
		}
		else
		{
			_mediaPlaylist->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
		}
	}
}

#include <QApplication>

void VideoPreview::keyPressEvent(QKeyEvent *event)
{
	switch (event->key()) {
	case Qt::Key_Left:
	case Qt::Key_Up:
		//if (QApplication::activeWindow() == this)
		{
			previousVideo();
		}
		break;
	case Qt::Key_Right:
	case Qt::Key_Down:
		//if (QApplication::activeWindow() == this)
		{
			nextVideo();
		}
		break;
	case Qt::Key_Space:
		handlePlayPause();
		break;
	}
	event->accept();
}

void VideoPreview::showEvent(QShowEvent *)
{
	_mediaPlayer->play();
}

void VideoPreview::hideEvent(QHideEvent *)
{
	_mediaPlayer->pause();
}

void VideoPreview::enterEvent(QEvent *)
{
	_toolbar->show();
}

void VideoPreview::leaveEvent(QEvent *)
{
	_toolbar->hide();
}

void VideoPreview::resizeEvent(QResizeEvent *)
{
	int w =_toolbar->width();
	int h =_toolbar->height();
	_toolbar->setGeometry((width()-w)/2,height()-h,w,h);
}
