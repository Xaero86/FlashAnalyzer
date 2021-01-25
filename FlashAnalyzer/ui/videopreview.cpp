#include "videopreview.h"

#include <QHBoxLayout>
#include <QBuffer>
#include <QVideoFrame>

#include "definevideostreamtag.h"

VideoPreview::VideoPreview(QWidget *parent)
	: QVideoWidget(parent),
	  _playlistMode(true),
	  _tag(nullptr)
{
	setBackgroundRole(QPalette::Base);
	setAutoFillBackground(true);

	_mediaPlayer = new QMediaPlayer(nullptr, QMediaPlayer::VideoSurface);
	_mediaPlayer->setVideoOutput(this);
	_mediaPlayer->setVolume(0);

	setLayout(new QHBoxLayout);
	setMinimumSize(200,200);

	connect(_mediaPlayer, SIGNAL(error(QMediaPlayer::Error)), this, SLOT(handleError(QMediaPlayer::Error)));
	connect(_mediaPlayer, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)), this, SLOT(handleMediaStateChanged(QMediaPlayer::MediaStatus)));
	connect(this, SIGNAL(spacePress()), this, SLOT(playPause()));
}

void VideoPreview::setTagVideo(Tag* tag, const QString &name)
{
	_tag = tag;
	if (tag == nullptr)
	{
		_mediaPlayer->setMedia(QMediaContent());
		return;
	}
	if (tag->isVideo())
	{
		DefineVideoStreamTag* videoTag = dynamic_cast<DefineVideoStreamTag*>(tag);
		if (!windowState().testFlag(Qt::WindowMaximized))
		{
			resize(videoTag->width(),videoTag->height());
		}

		setWindowFilePath(name);

		QBuffer* buffer = new QBuffer(_mediaPlayer);
		buffer->setData(videoTag->getFlv());
		buffer->open(QIODevice::ReadOnly);
		_mediaPlayer->setMedia(QMediaContent(),buffer);

		if (!isHidden())
		{
			_mediaPlayer->play();
		}
	}
}

void VideoPreview::handleError(QMediaPlayer::Error error)
{
	qDebug() << "error=" << error;
}

void VideoPreview::handleMediaStateChanged(QMediaPlayer::MediaStatus status)
{
	if (status == QMediaPlayer::EndOfMedia)
	{
		if (_playlistMode)
		{
			emit rightPress();
		}
		else if (_tag != nullptr)
		{
			DefineVideoStreamTag* videoTag = dynamic_cast<DefineVideoStreamTag*>(_tag);
			QBuffer *buffer = new QBuffer(_mediaPlayer);
			buffer->setData(videoTag->getFlv());
			buffer->open(QIODevice::ReadOnly);

			_mediaPlayer->setMedia(QMediaContent(),buffer);
			if (!isHidden())
			{
				_mediaPlayer->play();
			}
		}
	}
}

void VideoPreview::playPause()
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

void VideoPreview::keyPressEvent(QKeyEvent *event)
{
	if (event->key() == Qt::Key_Left)
	{
		emit leftPress();
	}
	else if (event->key() == Qt::Key_Right)
	{
		emit rightPress();
	}
	else if (event->key() == Qt::Key_Up)
	{
		emit upPress();
	}
	else if (event->key() == Qt::Key_Down)
	{
		emit downPress();
	}
	else if (event->key() == Qt::Key_Space)
	{
		emit spacePress();
	}
	else if (event->key() == Qt::Key_M)
	{
		_playlistMode = !_playlistMode;
	}
}

void VideoPreview::showEvent(QShowEvent *)
{
	_mediaPlayer->play();
}

void VideoPreview::hideEvent(QHideEvent *)
{
	_mediaPlayer->pause();
}
