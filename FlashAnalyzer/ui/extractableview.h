#ifndef EXTRACTABLEVIEW_H
#define EXTRACTABLEVIEW_H

#include <QTreeView>
#include <QMenu>
#include <QFileDialog>

#include "tag.h"

class ExtractableView : public QTreeView
{
	Q_OBJECT
public:
	ExtractableView(QWidget *parent = nullptr);

	void setModel(QAbstractItemModel *model) override;
	void setDefaultUrl(QUrl& url);

public slots:
	void selectImage(int pos);
	void selectVideo(int pos);
	void selectSound(int pos);

protected slots:
	void selChanged();
	void reqPreview();
	void prepareMenu(const QPoint &pos);
	void handleExtract();

signals:
	void imageSelected(Tag* tag, QString& name, int pos);
	void videoSelected(Tag* tag, QString& name, int pos);
	void soundSelected(Tag* tag, QString& name, int pos);
	void imagePreview();
	void videoPreview();
	void soundPreview();

private:
	QMenu*    _contextMenu;
	QAction*  _actionPreview;
	QAction*  _actionExtract;

	QUrl        _lastUsedPath;
	QFileDialog _saveDialog;
	QFileDialog _saveAllDialog;

	void extractTag(const QModelIndex &index, QString fileName = QString());
};

#endif // EXTRACTABLEVIEW_H
