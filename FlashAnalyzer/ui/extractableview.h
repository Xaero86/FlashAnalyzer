#ifndef EXTRACTABLEVIEW_H
#define EXTRACTABLEVIEW_H

#include <QTreeView>

#include "tag.h"

class ExtractableView : public QTreeView
{
	Q_OBJECT
public:
	ExtractableView(QWidget *parent = nullptr);

	void setModel(QAbstractItemModel *model) override;

public slots:
	void selectNext();
	void selectPrevious();

protected slots:
	void selChanged();
	void reqPreview();

signals:
	void tagSelected(Tag* tag, QString& name);
	void doubleClick(int type);
};

#endif // EXTRACTABLEVIEW_H
