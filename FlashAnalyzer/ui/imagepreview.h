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

	void setTagImage(Tag* tag, QString &name);

signals:
	void leftPress();
	void rightPress();
	void upPress();
	void downPress();

protected:
	void paintEvent(QPaintEvent *event);
	void keyPressEvent(QKeyEvent *event);

private:
	QImage	        _image;
};

#endif // IMAGEPREVIEW_H
