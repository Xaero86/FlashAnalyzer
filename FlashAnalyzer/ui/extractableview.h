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
	void selectNext();
	void selectPrevious();

protected slots:
	void selChanged();
	void reqPreview();
	void prepareMenu(const QPoint &pos);
	void handleExtract();

signals:
	void tagSelected(Tag* tag, QString& name);
	void doubleClick(int type);

private:
	QMenu*    _contextMenu;
	QAction*  _actionExtract;

	QUrl        _lastUsedPath;
	QFileDialog _saveDialog;
	QFileDialog _saveAllDialog;

	void extractTag(const QModelIndex &index, QString fileName = QString());
};

#endif // EXTRACTABLEVIEW_H
