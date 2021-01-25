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

	void setTagVideo(Tag* tag = nullptr, const QString &name = QString("Video preview"));

signals:
	void leftPress();
	void rightPress();
	void upPress();
	void downPress();
	void spacePress();

protected slots:
	void playPause();
	void handleError(QMediaPlayer::Error error);
	void handleMediaStateChanged(QMediaPlayer::MediaStatus status);

protected:
	void keyPressEvent(QKeyEvent *event) override;
	void showEvent(QShowEvent *event) override;
	void hideEvent(QHideEvent *event) override;

private:
	QMediaPlayer*   _mediaPlayer;
	bool            _playlistMode;
	Tag*            _tag;
};

#endif // VIDEOPREVIEW_H
