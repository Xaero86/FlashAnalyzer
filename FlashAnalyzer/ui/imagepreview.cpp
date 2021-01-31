#include "imagepreview.h"

#include <QHBoxLayout>
#include <QPainter>

#include "imagetag.h"

ImagePreview::ImagePreview(QWidget *parent)
	: QWidget(parent),
	  _imageIndex(0)
{
	setBackgroundRole(QPalette::Base);
	setAutoFillBackground(true);

	this->setLayout(new QHBoxLayout);
	setMinimumSize(200,200);
}

void ImagePreview::setTagImage(Tag* tag, const QString &name, int index)
{
	_image = QImage();
	if (tag == nullptr)
	{
		return;
	}
	if (tag->isImage())
	{
		_imageIndex = index;
		ImageTag* imageTag = dynamic_cast<ImageTag*>(tag);
		_image = imageTag->toQImage();
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
			resize(200,200);
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
	switch (event->key()) {
	case Qt::Key_Left:
	case Qt::Key_Up:
		emit imageChanged(_imageIndex-1);
		break;
	case Qt::Key_Right:
	case Qt::Key_Down:
		emit imageChanged(_imageIndex+1);
		break;
	}
}
