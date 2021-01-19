#include "videopreview.h"

#include <QHBoxLayout>
#include <QBuffer>
#include <QVideoFrame>

#include "definevideostreamtag.h"

VideoPreview::VideoPreview(QWidget *parent)
	: QVideoWidget(parent)
{
	setBackgroundRole(QPalette::Base);
	setAutoFillBackground(true);

	_mediaPlayer = new QMediaPlayer(nullptr, QMediaPlayer::VideoSurface);
	_mediaPlayer->setVideoOutput(this);

	setLayout(new QHBoxLayout);
	setMinimumSize(200,200);
}

void VideoPreview::setTagVideo(Tag* tag, QString &name)
{
	if (tag == nullptr)
	{
		return;
	}
	if (tag->isVideo())
	{
		DefineVideoStreamTag* videoTag = dynamic_cast<DefineVideoStreamTag*>(tag);

		resize(videoTag->width(),videoTag->height());

		setWindowFilePath(name);

		QByteArray ba(videoTag->getFlv());
		QBuffer buffer(&ba);
		_mediaPlayer->setMedia(QUrl(""), &buffer);
		_mediaPlayer->play();
	}
}

void VideoPreview::keyPressEvent(QKeyEvent *event)
{
	if(event->key() == Qt::Key_Left)
	{
		emit leftPress();
	}
	else if(event->key() == Qt::Key_Right)
	{
		emit rightPress();
	}
	else if(event->key() == Qt::Key_Up)
	{
		emit upPress();
	}
	else if(event->key() == Qt::Key_Down)
	{
		emit downPress();
	}
}
