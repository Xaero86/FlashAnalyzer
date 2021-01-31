#ifndef VIDEOPREVIEW_H
#define VIDEOPREVIEW_H

#include <QKeyEvent>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QPushButton>
#include <QCheckBox>
#include <QRadioButton>

class VideoPreview : public QWidget
{
	Q_OBJECT
public:
	VideoPreview(QWidget *parent = nullptr);

	void clearPlaylist();
	void addVideo(int pos, const QMediaContent &video);
	void selectVideo(int pos);

public slots:
	void nextVideo();
	void previousVideo();

signals:
	void videoChanged(int index);

protected slots:
	void handleIndexChanged(int position);
	void handleMediaChanged(const QMediaContent &content);
	void handlePlayerStateChanged(QMediaPlayer::State state);
	void handlePlayPause();
	void handlePlaybackMode();

protected:
	void keyPressEvent(QKeyEvent *event) override;
	void showEvent(QShowEvent *event) override;
	void hideEvent(QHideEvent *event) override;
	void enterEvent(QEvent *) override;
	void leaveEvent(QEvent *) override;
	void resizeEvent(QResizeEvent *) override;

private:
	QMediaPlayer*   _mediaPlayer;
	QMediaPlaylist* _mediaPlaylist;

	QVideoWidget*   _videoWidget;
	QWidget*        _toolbar;
	QPushButton*    _playButton;
	QPushButton*    _nextButton;
	QPushButton*    _prevButton;
	QCheckBox*      _loopCheckBox;
	QRadioButton*   _allRadio;
	QRadioButton*   _currentRadio;
};

#endif // VIDEOPREVIEW_H
