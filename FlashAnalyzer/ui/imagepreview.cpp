#include "imagepreview.h"

#include <QHBoxLayout>
#include <QPainter>

#include "imagetag.h"

ImagePreview::ImagePreview(QWidget *parent)
	: QWidget(parent)
{
	setBackgroundRole(QPalette::Base);
	setAutoFillBackground(true);

	this->setLayout(new QHBoxLayout);
}

void ImagePreview::setTagImage(Tag* tag, QString &name)
{
	_image = QImage();
	if (tag == nullptr)
	{
		return;
	}
	if (tag->isImage())
	{
		ImageTag* imageTag = dynamic_cast<ImageTag*>(tag);
		_image = QImage::fromData(reinterpret_cast<const unsigned char*>(imageTag->imageData()), imageTag->imageDataSize());
		if (!_image.isNull())
		{
			setWindowFilePath(name);
			if (!windowState().testFlag(Qt::WindowMaximized))
			{
				resize(_image.size());
			}
			repaint();
		}
		else
		{
			resize(200,100);
			repaint();
		}
	}
}

void ImagePreview::paintEvent(QPaintEvent * /* event */)
{
	QPainter painter(this);
	painter.fillRect(rect(), QColor(Qt::black));

	if (!_image.isNull() && (_image.width() > 0) && (_image.height() > 0))
	{
		qreal scaleX = (qreal) width()/(qreal) _image.width();
		qreal scaleY = (qreal) height()/(qreal) _image.height();
		qreal scale = qMin(scaleX, scaleY);
		int posX = (((qreal) width())/scale-((qreal) _image.width()))/2.0;
		int posY = (((qreal) height())/scale-((qreal) _image.height()))/2.0;
		QRect rect(posX, posY, _image.width(), _image.height());

		painter.save();
		painter.scale(scale, scale);
		painter.drawImage(rect, _image);
		painter.restore();
	}
}

void ImagePreview::keyPressEvent(QKeyEvent *event)
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
