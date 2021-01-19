#ifndef VIDEOPREVIEW_H
#define VIDEOPREVIEW_H

#include <QWidget>
#include <QKeyEvent>
#include <QMediaPlayer>
#include <QVideoWidget>

#include "tag.h"

class VideoPreview : public QVideoWidget
{
	Q_OBJECT
public:
	VideoPreview(QWidget *parent = nullptr);

	void setTagVideo(Tag* tag, QString &name);

signals:
	void leftPress();
	void rightPress();
	void upPress();
	void downPress();

protected:
	void keyPressEvent(QKeyEvent *event);

private:
	QMediaPlayer*  _mediaPlayer;
};

#endif // VIDEOPREVIEW_H
