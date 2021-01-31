#ifndef IMAGEPREVIEW_H
#define IMAGEPREVIEW_H

#include <QWidget>
#include <QKeyEvent>

#include "tag.h"

class ImagePreview : public QWidget
{
	Q_OBJECT
public:
	ImagePreview(QWidget *parent = nullptr);

	void setTagImage(Tag* tag = nullptr, const QString &name = QString("Image preview"), int index = 0);

signals:
	void imageChanged(int newIndex);

protected:
	void paintEvent(QPaintEvent *event);
	void keyPressEvent(QKeyEvent *event);

private:
	QImage	        _image;
	int             _imageIndex;
};

#endif // IMAGEPREVIEW_H
